

#include "../../include/minirt_bonus.h"

void	uv_map_sphere(t_hit *hit, unsigned int *px, \
	unsigned int *py, mlx_texture_t *image)
{
	t_vec3		normal;
	float		phi;
	float		theta;
	float		u;
	float		v;

	normal = vec_unit_vec(hit->hit_point, get_position(hit->obj));
	phi = atan2f(normal.z, normal.x);
	theta = acosf(normal.y);
	u = (phi / (2 * M_PI)) * -1;
	if (u < 0)
		u += 1;
	v = (theta / M_PI);
	if (v < 0)
		v += 1;
	(*px) = u * (image->width - 1);
	if ((*px) > (image->width - 1))
		(*px) = (image->width - 1);
	(*py) = v * (image->height - 1);
	if ((*py) > image->height - 1)
		(*py) = image->height - 1;
}

void	uv_map_plane(t_hit *hit, unsigned int *px, \
	unsigned int *py, mlx_texture_t *image)
{
	t_vec3	u_vec;
	t_vec3	v_vec;
	t_vec3	hit_to_point;
	float	u;
	float	v;

	u_vec = vec_cross(get_plane_direction(hit->obj), generate_vector(1, 0, 0));
	v_vec = vec_cross(get_plane_direction(hit->obj), u_vec);
	hit_to_point = vec_subs(hit->hit_point, get_position(hit->obj));
	u = vec_dot(hit_to_point, u_vec);
	v = vec_dot(hit_to_point, v_vec);
	u /= 30;
	v /= 35;
	u = fmod(u, 1.0f);
	if (u < 0)
		u += 1;
	v = fmod(v, 1.0f);
	if (v < 0)
		v += 1;
	*px = (unsigned int)(u * (image->width - 1));
	*py = (unsigned int)(v * (image->height - 1));
}

void	uv_map(t_hit *hit, unsigned int *px, \
	unsigned int *py, mlx_texture_t *image)
{
	if (hit->obj->type == SPHERE)
	{
		uv_map_sphere(hit, px, py, image);
	}
	else if (hit->obj->type == PLAN)
	{
		uv_map_plane(hit, px, py, image);
	}
}
