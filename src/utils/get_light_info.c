

#include "minirt.h"

t_vec3	get_light_position(void *packed_light)
{
	t_light	*light;

	light = (t_light *)packed_light;
	return (light->position);
}

float	get_light_intensity(void *packed_light)
{
	t_light	*light;

	light = (t_light *)packed_light;
	return (light->intensity);
}

t_color	get_light_color(void *packed_light)
{
	t_light	*light;

	light = (t_light *)packed_light;
	return (light->color);
}
