
#include "minirt.h"

//d is ray direction
t_vec3	get_d(t_ray_info ray)
{
	t_vec3	d;
	t_vec3	right;
	t_vec3	up;

	right = ray.right;
	up = ray.up;
	right = vec_scale(right, ray.x);
	up = vec_scale(up, ray.y);
	d = vec_add(ray.forward, vec_add(up, right));
	d = vec_norm(d);
	return (d);
}

//init helper to the routine
static void	init_directions(t_ray_info *ray)
{
	float		aspect_ratio;
	t_minirt	*minirt;

	minirt = get_minirt();
	aspect_ratio = (float)get_minirt()->image->width
		/ (float)get_minirt()->image->height;
	ray->height = atanf(get_minirt()->camera.field_of_view / 2.0f);
	ray->width = ray->height * aspect_ratio;
	ray->forward = get_minirt()->camera.direction;
	ray->right = vec_scale(vec_cross(ray->forward, up_guide()), ray->width);
	if (ray->forward.x == 0 && ray->forward.z == 0 && ray->forward.y == 1)
		ray->right = vec_scale(vec_cross(ray->forward, \
		vec_norm(generate_vector(0.05, 0.95, 0))), ray->width);
	else if (ray->forward.x == 0 && ray->forward.z == 0 && ray->forward.y == -1)
		ray->right = vec_scale(vec_cross(ray->forward, \
		vec_norm(generate_vector(-0.05, -0.95, 0))), ray->width);
	ray->right = vec_scale(ray->right, -1.0f);
	ray->up = vec_scale(vec_cross(vec_norm(ray->right), ray->forward),
			ray->height);
	ray->forward = vec_norm(ray->forward);
	vec_reset(&ray->d);
	minirt->cam_matrix = init_cam_matrix(ray->right, ray->up, ray->forward);
}

//init helper to a single ray in the routine
static void	pre_launch_operations(t_ray_info *ray)
{
	ray->x = 2.0f * ((float)ray->px + 0.5f) / (float)get_minirt()->image->width
		- 1;
	ray->y = 2.0f * ((float)ray->py + 0.5f) / (float)get_minirt()->image->height
		- 1;
	ray->first_hit = TRUE;
	ray->d = get_d(*ray);
}

//ray_launcher() without super-sampling
void	*routine(void *package)
{
	t_thread	*thread;
	t_shading	shade;

	thread = package;
	thread->ray.py = thread->index;
	while (thread->ray.py < thread->scr_height)
	{
		thread->ray.px = 0;
		while (thread->ray.px < thread->scr_width)
		{
			pre_launch_operations(&thread->ray);
			shade = single_ray(thread->ray, &thread->closest_hit);
			mlx_put_pixel(get_minirt()->image, thread->ray.px, thread->ray.py,
				(u_int32_t)get_rgba(shade.color, shade.intensity));
			thread->ray.px++;
		}
		thread->ray.py += THREAD_COUNT;
	}
	return (NULL);
}

//main function that launches the individual rays
void	ray_launcher(void)
{
	int			i;
	t_thread	thread[THREAD_COUNT];
	t_ray_info	ray;

	init_directions(&ray);
	map_erase(get_minirt());
	i = 0;
	while (i < THREAD_COUNT)
	{
		thread[i].ray = ray;
		thread[i].index = i;
		thread[i].scr_width = (int)get_minirt()->image->width;
		thread[i].scr_height = (int)get_minirt()->image->height;
		if (get_minirt()->mode == NORMAL)
			pthread_create(&thread[i].thread, NULL, &routine, &thread[i]);
		else if (get_minirt()->mode == SUPER)
			pthread_create(&thread[i].thread, NULL, &super_routine, &thread[i]);
		i++;
	}
	i = 0;
	while (i < THREAD_COUNT)
	{
		pthread_join(thread[i].thread, NULL);
		i++;
	}
}
