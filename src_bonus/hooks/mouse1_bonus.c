

#include "../../include/minirt_bonus.h"

static t_vec3	get_d_mouse(t_ray_info *ray)
{
	t_vec3	d;
	t_vec3	right;
	t_vec3	up;

	right = ray->right;
	up = ray->up;
	right = vec_scale(right, ray->x);
	up = vec_scale(up, ray->y);
	d = vec_add(ray->forward, vec_add(up, right));
	d = vec_norm(d);
	return (d);
}

static void	init_directions_mouse(t_ray_info *ray)
{
	t_mat4	camera;
	float	aspect_ratio;

	camera = get_minirt()->cam_matrix;
	aspect_ratio = (float)get_minirt()->image->width / \
		(float)get_minirt()->image->height;
	ray->height = atanf(get_minirt()->camera.field_of_view / 2.0f);
	ray->width = ray->height * aspect_ratio;
	ray->forward = get_minirt()->camera.direction;
	ray->right = vec_scale(vec_cross(ray->forward, up_guide_mouse()), \
		ray->width * -1);
	ray->up = vec_scale(vec_cross(vec_norm(ray->right), ray->forward), \
		ray->height);
	vec_reset(&ray->d);
	camera = init_cam_matrix(ray->right, ray->up, ray->forward);
	get_minirt()->cam_matrix = camera;
}

/* 
Ray-picking objects based on mouse input in order to select an object
on the screen
 */
static void	ray_mouse(float x, float y)
{
	t_ray_info	ray;
	t_hit		closest_hit;

	init_directions_mouse(&ray);
	ray.x = 2.0f * ((float)x + 0.5f) / (float)get_minirt()->image->width - 1;
	ray.y = 2.0f * ((float)y + 0.5f) / (float)get_minirt()->image->height - 1;
	ray.d = get_d_mouse(&ray);
	find_closest_object(&ray, &closest_hit);
	if (closest_hit.obj)
		get_minirt()->obj_selected = closest_hit.obj;
	else
	{
		get_minirt()->selected = CAMERA;
		printf("Object selected = camera\n");
	}
}

/* 
Handles mouse input events.
When the left mouse button is pressed, it retrieves the current
mouse coordinates and prints them to the console.
 */
void	minirt_mouse(mouse_key_t button, action_t action, \
	modifier_key_t mods, void *param)
{
	int32_t		x_mouse;
	int32_t		y_mouse;
	t_minirt	*minirt;

	(void)button;
	(void)action;
	(void)mods;
	minirt = (t_minirt *)param;
	if (mlx_is_mouse_down(minirt->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		mlx_get_mouse_pos(minirt->mlx, &x_mouse, &y_mouse);
		printf("Coordinates :\n");
		printf("x_mouse = %d and y_mouse = %d\n", x_mouse, y_mouse);
		ray_mouse((float)x_mouse, (float)y_mouse);
	}
}
