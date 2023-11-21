

#include "minirt.h"

/* 
MATRIX INIT
This function initializes a transformation matrix for our camera,
where it aligns the camera's orientation axes (right, up, and forward)
and sets its position. It returns this matrix, representing the
transformation from world space to camera space.
 */
t_mat4	init_cam_matrix(t_vec3 right, t_vec3 up, t_vec3 forward)
{
	t_mat4	cam_mat;

	right = vec_norm(right);
	up = vec_norm(up);
	forward = vec_norm(forward);
	cam_mat = identity_matrix();
	cam_mat.p[0][0] = right.x;
	cam_mat.p[0][1] = right.y;
	cam_mat.p[0][2] = right.z;
	cam_mat.p[1][0] = up.x;
	cam_mat.p[1][1] = up.y;
	cam_mat.p[1][2] = up.z;
	cam_mat.p[2][0] = forward.x;
	cam_mat.p[2][1] = forward.y;
	cam_mat.p[2][2] = forward.z;
	cam_mat.p[3][0] = get_minirt()->camera.position.x;
	cam_mat.p[3][1] = get_minirt()->camera.position.y;
	cam_mat.p[3][2] = get_minirt()->camera.position.z;
	return (cam_mat);
}

/*
MATRIX ROTATION
A rotation matrix rotates an object about one of the three coordinate axes,
or any arbitrary vector.
ROT on axe X
 _                   _
|  1    0     0    0  |
|  0   cos𝜃  sin𝜃   0  |
|  0  -sin𝜃  cos𝜃   0  |
|_ 0    0     0    1 _|
To convert from degrees to radians, multiply the number of degrees by π/180.
*/
t_mat4	matrix_rotx(float angle)
{
	t_mat4	mat;
	float	rad;

	mat = identity_matrix();
	rad = angle * M_PI / 180.0f;
	mat.p[1][1] = cosf(rad);
	mat.p[1][2] = sinf(rad);
	mat.p[2][1] = -sinf(rad);
	mat.p[2][2] = cosf(rad);
	return (mat);
}

/*
MATRIX ROTATION
A rotation matrix rotates an object about one of the three coordinate axes,
or any arbitrary vector.
ROT on axe Y
 _                   _
|  cos𝜃  0  -sin𝜃   0  |
|   0    1    0     0  |
|  sin𝜃  0   cos𝜃   0  |
|_  0    0    0     1 _|
To convert from degrees to radians, multiply the number of degrees by π/180.
*/
t_mat4	matrix_roty(float angle)
{
	t_mat4	mat;
	float	rad;

	rad = angle * M_PI / 180.0f;
	mat = identity_matrix();
	mat.p[0][0] = cosf(rad);
	mat.p[0][2] = -sinf(rad);
	mat.p[2][0] = sinf(rad);
	mat.p[2][2] = cosf(rad);
	return (mat);
}

/*
MATRIX ROTATION
A rotation matrix rotates an object about one of the three coordinate axes,
or any arbitrary vector.
ROT on axe Z
 _                   _
|  cos𝜃  sin𝜃  0  0  |
| -sin𝜃  cos𝜃  0  0  |
|   0     0    1  0  |
|_  0     0    0  1 _|
To convert from degrees to radians, multiply the number of degrees by π/180.
*/
t_mat4	matrix_rotz(float angle)
{
	t_mat4	mat;
	float	rad;

	rad = angle * M_PI / 180.0f;
	mat = identity_matrix();
	mat.p[0][0] = cos(rad);
	mat.p[0][1] = sin(rad);
	mat.p[1][0] = -sin(rad);
	mat.p[1][1] = cos(rad);
	return (mat);
}
