

#include "../../include/minirt_bonus.h"

//special case for sun in reflexion to make it look more realistic
void	sun_special_reflexion_case(t_shading *shade, float *multiplier,
	t_hit closest_hit)
{
	if (get_obj_material(closest_hit.obj)->id == SUN)
	{
		shade->intensity *= 1.2f;
		if (shade->intensity > 255.0f)
			shade->intensity = 255.0f;
		*multiplier *= 5;
	}
}

//helper to calc_reflexion()
void	init_calc_reflexion(t_ray_info *ray, t_vec3 v, t_hit *hit)
{
	t_vec3		n;

	n = get_normal_vec(hit);
	ray->first_hit = TRUE;
	ray->d = vec_unit_vec(vec_scale(n, 2 * vec_dot(v, n)), v);
}

//shoots recursive rays to get values of the reflexions
void	calc_reflexion(t_hit *hit, t_vec3 v, t_shading *shade,
		int *refl)
{
	t_ray_info	ray;
	t_hit		closest_hit;
	float		mult;
	t_shading	new_shading;

	if (++(*refl) > NUMBER_OF_REFLEXIONS)
		return ;
	init_calc_reflexion(&ray, v, hit);
	find_closest_hit(ray, &closest_hit, hit->hit_point);
	if (closest_hit.obj)
	{
		closest_hit.hit_point = vec_add(hit->hit_point, vec_scale(ray.d,
					closest_hit.t));
		closest_hit.hit_point = vec_add(closest_hit.hit_point,
				vec_scale(get_normal_vec(&closest_hit), 0.01));
		mult = get_obj_material(hit->obj)->reflexion / sqrtf(closest_hit.t);
		sun_special_reflexion_case(shade, &mult, closest_hit);
		new_shading.intensity = shading_intensity(&closest_hit,
				get_normal_vec(&closest_hit), shade, *refl);
		new_shading.color = get_texture_color(&closest_hit);
		new_shading.color = shading_color(&closest_hit, &new_shading, refl,
				vec_scale(ray.d, -1));
		shade->color = color_add(shade->color, color_scale(new_shading.color,
					mult * new_shading.intensity / 255.0f));
	}
}
