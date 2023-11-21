

#include "minirt.h"

//super_smaple() helper
static void	super_pre_launch_operations(t_ray_info *ray, float px_plus,
		float py_plus)
{
	ray->x = 2.0f * ((float)ray->px + px_plus)
		/ (float)get_minirt()->image->width - 1;
	ray->y = 2.0f * ((float)ray->py + py_plus)
		/ (float)get_minirt()->image->height - 1;
	ray->first_hit = TRUE;
	ray->d = get_d(*ray);
}

//super_smaple() helper
static void	super_sample_init(int *i, float *j, float *k)
{
	*i = -1;
	*j = 0.17f;
	*k = 0.17f;
}

//super_smaple() helper
static void	super_sample_update_vars(int i, float *j, float *k)
{
	*j += 0.34f;
	if (*j > 1)
		*j = 0.17f;
	if ((i + 1) % 3 == 0)
		*k += 0.34f;
}

//helper to super_routine()
static t_shading	super_sample(t_thread *thread)
{
	t_shading	shades[9];
	t_shading	result;
	int			i;
	float		j;
	float		k;

	super_sample_init(&i, &j, &k);
	while (++i < 9)
	{
		super_pre_launch_operations(&thread->ray, j, k);
		shades[i] = single_ray(thread->ray, &thread->closest_hit);
		super_sample_update_vars(i, &j, &k);
	}
	result.color = no_color();
	result.intensity = 0;
	i = -1;
	while (++i < 9)
	{
		result.color = color_add(result.color, shades[i].color);
		result.intensity += shades[i].intensity;
	}
	result.color = color_scale(result.color, 0.11111111f);
	result.intensity /= 9;
	return (result);
}

//super-sample version of the ray_launcher()
void	*super_routine(void *package)
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
			shade = super_sample(thread);
			mlx_put_pixel(get_minirt()->image, thread->ray.px, thread->ray.py,
				(u_int32_t)get_rgba(shade.color, shade.intensity));
			thread->ray.px++;
		}
		thread->ray.py += THREAD_COUNT;
	}
	return (NULL);
}
