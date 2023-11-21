

#include "../../include/minirt_bonus.h"

void	cone_rotation(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	t_vec3	new_dir;
	t_mat4	mat;

	dir = get_cone_direction(minirt->obj_selected);
	if (key == MLX_KEY_K)
		mat = matrix_rotx(5);
	if (key == MLX_KEY_I)
		mat = matrix_rotx(-5);
	if (key == MLX_KEY_L)
		mat = matrix_roty(5);
	if (key == MLX_KEY_J)
		mat = matrix_roty(-5);
	if (key == MLX_KEY_O)
		mat = matrix_rotz(5);
	if (key == MLX_KEY_U)
		mat = matrix_rotz(-5);
	new_dir = matrix_vec_mult(mat, dir);
	change_direction(minirt->obj_selected, new_dir);
}

void	cyl_rotation(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	t_vec3	new_dir;
	t_mat4	mat;

	dir = get_cylinder_direction(minirt->obj_selected);
	if (key == MLX_KEY_K)
		mat = matrix_rotx(5);
	if (key == MLX_KEY_I)
		mat = matrix_rotx(-5);
	if (key == MLX_KEY_L)
		mat = matrix_roty(5);
	if (key == MLX_KEY_J)
		mat = matrix_roty(-5);
	if (key == MLX_KEY_O)
		mat = matrix_rotz(5);
	if (key == MLX_KEY_U)
		mat = matrix_rotz(-5);
	new_dir = matrix_vec_mult(mat, dir);
	change_direction(minirt->obj_selected, new_dir);
}

void	plane_rotation_pitch(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	t_vec3	new_dir;
	t_mat4	mat;

	dir = get_plane_direction(minirt->obj_selected);
	if (key == MLX_KEY_I)
		mat = matrix_rotx(5);
	if (key == MLX_KEY_K)
		mat = matrix_rotx(-5);
	new_dir = matrix_vec_mult(mat, dir);
	change_direction(minirt->obj_selected, new_dir);
}

/* 
Matrix rotation doesn't work with roll rotation, had to use 
the old function for this one.
 */
void	plane_rotation_roll(t_minirt *minirt, keys_t key)
{
	t_vec3	dir;
	float	rad;

	if (key == MLX_KEY_L)
	{
		rad = 5 * M_PI / 180.0f;
		dir.x = cos(rad) * dir.x - sin(rad) * dir.y;
		dir.y = sin(rad) * dir.x + cos(rad) * dir.y;
	}
	if (key == MLX_KEY_J)
	{
		rad = -5 * M_PI / 180.0f;
		dir.x = cos(rad) * dir.x - sin(rad) * dir.y;
		dir.y = sin(rad) * dir.x + cos(rad) * dir.y;
	}
	change_direction(minirt->obj_selected, dir);
}
