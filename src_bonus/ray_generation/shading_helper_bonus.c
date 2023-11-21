

#include "../../include/minirt_bonus.h"

//light direction from the hit point
t_vec3	get_light_dir(t_hit *hit, void *current_light)
{
	t_vec3	w;
	t_vec3	light_position;

	light_position = get_light_position(current_light);
	w = vec_subs(light_position, hit->hit_point);
	w = vec_norm(w);
	return (w);
}

//geo term will determine the shading intensity
float	get_geo_term(t_hit *hit, void *current_light, t_vec3 n)
{
	t_vec3	w;
	float	geo_term;

	w = get_light_dir(hit, current_light);
	geo_term = vec_dot(n, w);
	return (geo_term);
}

//helper to shadow_ray_hits()
void	init_shadow_rays(t_vec3 *d, float *t, t_list **light, t_hit *hit)
{
	t_vec3	w;

	w = get_light_position((*light)->content);
	*d = vec_unit_vec(w, hit->hit_point);
	*t = vec_mag(vec_subs(w, hit->hit_point));
}

//checks if an object is in the shadow
bool	shadow_ray_hits(t_hit *hit, t_list **light)
{
	t_vec3	d;
	float	t;
	t_list	*current;
	t_hit	new_hit;

	init_shadow_rays(&d, &t, light, hit);
	current = get_minirt()->objects;
	while (current)
	{
		if (get_obj_material(current->content)->id == SUN
			|| hit->obj->obj == current->content)
		{
			current = current->next;
			continue ;
		}
		find_hit(d, current->content, &new_hit, hit->hit_point);
		if (new_hit.obj && new_hit.t < t - 0.001)
		{
			(*light) = (*light)->next;
			return (TRUE);
		}
		current = current->next;
	}
	return (FALSE);
}
