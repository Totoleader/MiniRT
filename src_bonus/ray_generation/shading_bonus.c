

#include "../../include/minirt_bonus.h"

//adds color of the light to the object
void	add_light_color(t_shading *shade, void *light, float light_intensity,
		int refl)
{
	t_color	coloradd;

	if (refl > 1)
		return ;
	light_intensity /= 255.0f;
	coloradd = color_scale(get_light_color(light), light_intensity);
	shade->color = color_add(shade->color, coloradd);
	coloradd = color_scale(get_minirt()->ambiant_light.color,
			get_minirt()->ambiant_light.intensity);
	shade->color = color_add(shade->color, coloradd);
}

//gets the intensity of the object depending on lights positions
float	shading_intensity(t_hit *hit, t_vec3 n, t_shading *shade, int refl)
{
	t_list	*current;
	float	ambiant_light;
	float	light_intensity;
	float	current_intensity;

	ambiant_light = 255.0f * get_minirt()->ambiant_light.intensity;
	light_intensity = ambiant_light;
	if (get_obj_material(hit->obj)->id == SUN)
		return (255.0f);
	current = get_minirt()->lights;
	while (current)
	{
		if (shadow_ray_hits(hit, &current))
			continue ;
		current_intensity = 0.0f;
		if (get_geo_term(hit, current->content, n) > 0.0f)
			current_intensity = MIN(get_geo_term(hit, current->content, n)
					* 255.0f * get_light_intensity(current->content), 255.0f);
		add_light_color(shade, current->content, current_intensity, refl);
		if (MAX(current_intensity, ambiant_light) > light_intensity)
			light_intensity = MAX(current_intensity, ambiant_light);
		current = current->next;
	}
	return (light_intensity);
}

void	calc_specular_effect(t_hit *hit, t_vec3 n, t_vec3 v, t_shading *shade)
{
	t_shading	spec;
	t_vec3		h;
	float		coeff;
	float		current_coeff;
	t_list		*current;

	current = get_minirt()->lights;
	coeff = 0;
	while (current)
	{
		h = vec_norm(vec_add(get_light_dir(hit, current->content), v));
		current_coeff = pow(MAX(vec_dot(n, h), 0.0f), \
			get_obj_material(hit->obj)->shine
				* pow(get_light_intensity(current->content), 1.4f));
		if (current_coeff > coeff)
		{
			coeff = current_coeff;
			spec.color = get_specular_color(shade->color, hit,
					get_light_intensity(current->content));
			spec.intensity = get_light_intensity(current->content) * 255.0f;
		}
		current = current->next;
	}
	shade->intensity += coeff * (spec.intensity - shade->intensity);
	shade->color = color_add(shade->color, color_scale(spec.color, coeff));
}

//gets the right rgb value of the obj without reflexions
t_color	shading_color(t_hit *hit, t_shading *shade, int *refl,
		t_vec3 v)
{
	t_vec3		n;
	t_material	*mat;

	n = get_normal_vec(hit);
	mat = get_obj_material(hit->obj);
	if (mat->shine != 0)
		calc_specular_effect(hit, n, v, shade);
	if (mat->reflexion != 0)
		calc_reflexion(hit, v, shade, refl);
	return (shade->color);
}

//main shading function
t_shading	shading(t_hit *hit)
{
	t_vec3		n;
	t_shading	shade;
	int			refl;
	t_vec3		v;
	t_color		coloradd;

	v = vec_unit_vec(get_minirt()->camera.position, hit->hit_point);
	refl = 0;
	shade.color = get_texture_color(hit);
	n = get_normal_vec(hit);
	shade.intensity = shading_intensity(hit, n, &shade, refl);
	shade.color = shading_color(hit, &shade, &refl, v);
	coloradd = color_scale(get_minirt()->ambiant_light.color,
			get_minirt()->ambiant_light.intensity);
	shade.color = color_add(shade.color, coloradd);
	shade.color = max_color(shade.color);
	return (shade);
}
