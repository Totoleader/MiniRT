

#include "../../include/minirt_bonus.h"

/*
Combines four individual channel bytes into a single integer using
bit-shifting
Use with mlx_put_pixel as 4th param (uint_32 color)
*/
int	get_rgba(t_color color, float a)
{
	return ((int)color.r << 24 | (int)color.g << 16 \
		| (int)color.b << 8 | (int)a);
}

t_color	no_color(void)
{
	t_color	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	return (color);
}

/* 
Returns a modified color with only the sp¯ecular reflection,
where the intensity is determined by the original intensity,
the material's specular factor, and a power function
 */
t_color	get_specular_color(t_color obj_color, t_hit *hit, float color_intensity)
{
	t_color	color;

	obj_color.r = 0;
	color_intensity = pow(color_intensity, 1.2) * 255.0f
		* get_obj_material(hit->obj)->specular_factor;
	color.r = color_intensity;
	color.b = color_intensity;
	color.g = color_intensity;
	return (color);
}

t_color	color_scale(t_color v, float scale)
{
	t_color	res;

	res.r = v.r * scale;
	res.g = v.g * scale;
	res.b = v.b * scale;
	return (res);
}

t_color	color_add(t_color v1, t_color v2)
{
	t_color	res;

	res.r = v1.r + v2.r;
	res.g = v1.g + v2.g;
	res.b = v1.b + v2.b;
	return (res);
}
