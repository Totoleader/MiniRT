

#include "../../include/minirt_bonus.h"

void	keys_camera(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		camera_translation_x(minirt, keydata.key);
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		camera_translation_z(minirt, keydata.key);
	else if (keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_E)
		camera_translation_y(minirt, keydata.key);
	else if (keydata.key == MLX_KEY_I || keydata.key == MLX_KEY_K)
		camera_rotation_pitch(minirt, keydata.key);
	else if (keydata.key == MLX_KEY_J || keydata.key == MLX_KEY_L)
		camera_rotation_yaw(minirt, keydata.key);
	ray_launcher();
}

/* 
	Handles hook for lights;
	Adjust the intensity of the light source and perform
	translation operations on the light source's position.
 */
void	keys_light(mlx_key_data_t keydata, void *param)
{
	t_light		*light;
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	light = (t_light *)minirt->lights->content;
	if (keydata.key == MLX_KEY_EQUAL && light->intensity < 1.0f)
		light->intensity += 0.1f;
	else if (keydata.key == MLX_KEY_MINUS && light->intensity > 0.1f)
		light->intensity -= 0.1f;
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		light_translation(minirt, keydata.key, 'x');
	else if (keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_E)
		light_translation(minirt, keydata.key, 'y');
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		light_translation(minirt, keydata.key, 'z');
	ray_launcher();
}
