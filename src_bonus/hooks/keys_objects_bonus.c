

#include "../../include/minirt_bonus.h"

void	keys_sphere(mlx_key_data_t keydata, void *param)
{
	float		*radius;
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	radius = get_radius(minirt->obj_selected);
	if (keydata.key == MLX_KEY_EQUAL)
		*radius += 1.0f;
	if (keydata.key == MLX_KEY_MINUS && *radius > 1.0f)
		*radius -= 1.0f;
	ray_launcher();
}

void	keys_cylinder(mlx_key_data_t keydata, void *param)
{
	float			*radius;
	float			*height;
	t_minirt		*minirt;
	static bool		flag = false;

	minirt = (t_minirt *)param;
	height = get_height(minirt->obj_selected);
	radius = get_radius(minirt->obj_selected);
	if (keydata.key == MLX_KEY_H)
		flag = true;
	else if (keydata.key == MLX_KEY_R)
		flag = false;
	if (keydata.key == MLX_KEY_EQUAL && flag == true)
		*height += 1.0f;
	else if (keydata.key == MLX_KEY_MINUS && *height > 1.0f && flag == true)
		*height -= 1.0f;
	else if (keydata.key == MLX_KEY_EQUAL && flag == false)
		*radius += 1.0f;
	else if (keydata.key == MLX_KEY_MINUS && *radius > 1.0f && flag == false)
		*radius -= 1.0f;
	ray_launcher();
}

void	keys_cone(mlx_key_data_t keydata, void *param)
{
	float			*angle;
	float			*height;
	t_minirt		*minirt;
	static bool		flag = false;

	minirt = (t_minirt *)param;
	height = get_height(minirt->obj_selected);
	angle = get_angle(minirt->obj_selected);
	if (keydata.key == MLX_KEY_H)
		flag = true;
	else if (keydata.key == MLX_KEY_R)
		flag = false;
	if (keydata.key == MLX_KEY_EQUAL && flag == true)
		*height += 1.0f;
	else if (keydata.key == MLX_KEY_MINUS && *height > 1.0f && flag == true)
		*height -= 1.0f;
	else if (keydata.key == MLX_KEY_EQUAL && flag == false)
		*angle += 1.0f * (M_PI / 180.0f);
	else if (keydata.key == MLX_KEY_MINUS && *angle > 0.25f && flag == false)
		*angle -= 1.0 * (M_PI / 180.0f);
	ray_launcher();
}

void	keys_object2(mlx_key_data_t keydata, void *param)
{
	if (get_minirt()->selected == SPHERE)
	{
		keys_sphere(keydata, param);
		keys_translation(keydata, param);
	}
	else if (get_minirt()->selected == CYLINDRE)
	{
		keys_rotation(keydata, param);
		keys_translation(keydata, param);
		keys_cylinder(keydata, param);
	}
	else if (get_minirt()->selected == CONE)
	{
		keys_rotation(keydata, param);
		keys_translation(keydata, param);
		keys_cone(keydata, param);
	}
	else if (get_minirt()->selected == PLAN)
	{
		keys_rotation(keydata, param);
		keys_translation(keydata, param);
	}
}

void	keys_object1(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_C)
	{
		get_minirt()->selected = CAMERA;
		printf("Object selected = camera\n");
	}
	if (keydata.key == MLX_KEY_BACKSPACE)
	{
		get_minirt()->selected = LIGHT;
		printf("Object selected = light\n");
	}
	if (get_minirt()->selected == CAMERA)
		keys_camera(keydata, param);
	if (get_minirt()->selected == LIGHT)
		keys_light(keydata, param);
}
