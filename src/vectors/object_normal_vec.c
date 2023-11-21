

#include "minirt.h"

/* 
Surface normal vector for a sphere :
	N = nrm(P - C)
	P = point on the sphere and C = center of the sphere
 */
static t_vec3	sphere_normal(t_hit *hit)
{
	t_vec3	n;
	t_vec3	hit_point;
	t_vec3	sphere_center;

	hit_point = vec_copy(hit->hit_point);
	sphere_center = vec_copy(get_position(hit->obj));
	n = vec_subs(hit_point, sphere_center);
	n = vec_norm(n);
	return (n);
}

static t_vec3	modified_sphere_normal(t_hit *hit)
{
	t_vec3	n;
	t_color	normap_val;
	t_vec3	t;
	t_vec3	b;
	float	distance;

	n = sphere_normal(hit);
	if (get_obj_material(hit->obj)->norm_map)
	{
		distance = vec_mag(vec_subs(hit->hit_point, \
			get_minirt()->camera.position));
		distance = 1.0 + 0.001f * pow(distance, 2);
		normap_val = get_normap_value(hit);
		normap_val = color_scale(normap_val, 2.0f / 255.0f);
		normap_val.r -= 1.0f;
		normap_val.g -= 1.0f;
		normap_val.b -= 1.0f;
		t = vec_norm(vec_cross(n, generate_vector(1, 0, 0)));
		t = vec_scale(t, normap_val.r / distance);
		b = vec_cross(n, t);
		b = vec_scale(b, normap_val.g / distance);
		n = vec_norm(vec_add(n, vec_add(t, vec_scale(b, normap_val.g))));
	}
	return (n);
}

t_vec3	get_normal_vec(t_hit *hit)
{
	if (hit->obj->type == SPHERE)
	{
		return (modified_sphere_normal(hit));
	}
	else if (hit->obj->type == PLAN)
	{
		return (vec_norm(get_plane_direction(hit->obj)));
	}
	else if (hit->obj->type == CYLINDRE)
	{
		return (hit->normal);
	}
	return (generate_vector(0, 0, 0));
}
