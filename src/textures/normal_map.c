

#include "minirt.h"

t_color	get_normap_value(t_hit *hit)
{
	t_material		*mat;
	t_color			color;
	unsigned int	px;
	unsigned int	py;
	unsigned int	p_xy;

	mat = get_obj_material(hit->obj);
	uv_map(hit, &px, &py, mat->norm_map);
	p_xy = 4 * (py * mat->norm_map->width + px);
	color.r = mat->norm_map->pixels[p_xy];
	color.g = mat->norm_map->pixels[p_xy + 1];
	color.b = mat->norm_map->pixels[p_xy + 2];
	return (color);
}
