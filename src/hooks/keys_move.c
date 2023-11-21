

#include "minirt.h"

/* 
handles keyboard input for rotating objects
 */
void	keys_rotation(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (minirt->selected == PLAN && (keydata.key == MLX_KEY_I
			|| keydata.key == MLX_KEY_K))
		plane_rotation_pitch(minirt, keydata.key);
	if (minirt->selected == PLAN && (keydata.key == MLX_KEY_J
			|| keydata.key == MLX_KEY_L))
		plane_rotation_roll(minirt, keydata.key);
	if (minirt->selected == CYLINDRE && (keydata.key == MLX_KEY_J
			|| keydata.key == MLX_KEY_L || keydata.key == MLX_KEY_I
			|| keydata.key == MLX_KEY_K || keydata.key == MLX_KEY_L
			|| keydata.key == MLX_KEY_U || keydata.key == MLX_KEY_O))
		cyl_rotation(minirt, keydata.key);
	ray_launcher();
}

/* 
handles keyboard input for translating objects
 */
void	keys_translation(mlx_key_data_t keydata, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		object_translation(minirt, keydata.key, 'x');
	else if (keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_E)
		object_translation(minirt, keydata.key, 'y');
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		object_translation(minirt, keydata.key, 'z');
	ray_launcher();
}
