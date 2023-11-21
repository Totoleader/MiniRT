

#include "minirt.h"

/* 
Updates the direction of the camera by setting
 its components to the new direction provided as an argument.
 */
static void	update_d_yaw(t_minirt *minirt, t_vec3 new_dir)
{
	minirt->camera.direction.x = new_dir.x;
	minirt->camera.direction.y = new_dir.y;
	minirt->camera.direction.z = new_dir.z;
}

/* 
Performs yaw rotation of the camera based on 
the specified key inputs (J and L), generating a yaw matrix 
and updating the camera direction accordingly.
 */
void	camera_rotation_yaw(t_minirt *minirt, keys_t key)
{
	t_mat4	yaw;
	t_vec3	new_dir;

	if (key == MLX_KEY_J)
		yaw = matrix_roty(5);
	if (key == MLX_KEY_L)
		yaw = matrix_roty(-5);
	new_dir = matrix_vec_mult(yaw, minirt->camera.direction);
	update_d_yaw(minirt, new_dir);
}

/* 
Updates the direction of the camera to match the third row (z-axis)
of the camera matrix.
 */
static void	update_d_pitch(t_minirt *minirt)
{
	minirt->camera.direction.x = minirt->cam_matrix.p[2][0];
	minirt->camera.direction.y = minirt->cam_matrix.p[2][1];
	minirt->camera.direction.z = minirt->cam_matrix.p[2][2];
}

/* 
Performs pitch rotation of the camera based on the specified 
key inputs (I and K), generating a pitch matrix and updating 
both the camera matrix and direction.
 */
void	camera_rotation_pitch(t_minirt *minirt, keys_t key)
{
	t_mat4	pitch;

	if (key == MLX_KEY_I && minirt->camera.direction.y < 0.85f)
	{
		pitch = matrix_rotx(5.0f);
		minirt->cam_matrix = matrix_mult(pitch, minirt->cam_matrix);
		update_d_pitch(minirt);
	}
	else if (key == MLX_KEY_K && minirt->camera.direction.y > -0.85f)
	{
		pitch = matrix_rotx(-5.0f);
		minirt->cam_matrix = matrix_mult(pitch, minirt->cam_matrix);
		update_d_pitch(minirt);
	}
}
