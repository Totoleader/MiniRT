

#include "../../include/minirt_bonus.h"

/* 
Handle camera translation along the z-axis, y-axis and x-axis,
 based on specific key inputs, and update the camera's position accordingly.
 */
void	camera_translation_z(t_minirt *minirt, keys_t key)
{
	t_vec3	move;

	move = move_init(minirt, 'z');
	if (key == MLX_KEY_W)
		minirt->camera.position = vec_add(minirt->camera.position, move);
	else if (key == MLX_KEY_S)
		minirt->camera.position = vec_subs(minirt->camera.position, move);
}

void	camera_translation_y(t_minirt *minirt, keys_t key)
{
	t_vec3	move;

	move = move_init(minirt, 'y');
	if (key == MLX_KEY_Q)
		minirt->camera.position = vec_add(minirt->camera.position, move);
	else if (key == MLX_KEY_E)
		minirt->camera.position = vec_subs(minirt->camera.position, move);
}

void	camera_translation_x(t_minirt *minirt, keys_t key)
{
	t_vec3	move;

	move = move_init(minirt, 'x');
	if (key == MLX_KEY_D)
		minirt->camera.position = vec_add(minirt->camera.position, move);
	else if (key == MLX_KEY_A)
		minirt->camera.position = vec_subs(minirt->camera.position, move);
}
