

#include "minirt.h"

/* 
Updates the position vector pos by adding or subtracting
a specified move vector based on the direction indicated
by the character c.
 */
void	new_pos(t_vec3 *pos, t_vec3 move, char c)
{
	if (c == '-')
	{
		pos->x -= move.x;
		pos->y -= move.y;
		pos->z -= move.z;
	}
	else if (c == '+')
	{
		pos->x += move.x;
		pos->y += move.y;
		pos->z += move.z;
	}
}

/* 
Initializes a move vector based on the given axis and camera matrix.
Calculates move which represents a displacement in the specified
axis relative to the camera's orientation.
 */
t_vec3	move_init(t_minirt *minirt, char axis)
{
	t_vec3	move;

	if (axis == 'x')
	{
		move.x = minirt->cam_matrix.p[0][0] * 0.5;
		move.y = minirt->cam_matrix.p[0][1] * 0.5;
		move.z = minirt->cam_matrix.p[0][2] * 0.5;
	}
	if (axis == 'y')
	{
		move.x = minirt->cam_matrix.p[1][0] * 0.5;
		move.y = minirt->cam_matrix.p[1][1] * 0.5;
		move.z = minirt->cam_matrix.p[1][2] * 0.5;
	}
	if (axis == 'z')
	{
		move.x = minirt->cam_matrix.p[2][0] * 0.5;
		move.y = minirt->cam_matrix.p[2][1] * 0.5;
		move.z = minirt->cam_matrix.p[2][2] * 0.5;
	}
	return (move);
}

void	object_translation(t_minirt *minirt, keys_t key, char axis)
{
	char	c;
	t_vec3	pos;
	t_vec3	move;

	move = move_init(minirt, axis);
	pos = get_position(minirt->obj_selected);
	if (key == MLX_KEY_S || key == MLX_KEY_Q || key == MLX_KEY_A)
	{
		c = '-';
		new_pos(&pos, move, c);
	}
	else if (key == MLX_KEY_W || key == MLX_KEY_E || key == MLX_KEY_D)
	{
		c = '+';
		new_pos(&pos, move, c);
	}
	change_position(minirt->obj_selected, pos);
}
