

#include "minirt.h"

//helps free in functions below
void	free_parse_functions(char **split)
{
	free(split[0]);
	free(split[1]);
	free(split[2]);
	free(split);
}

//helps parse triplets of coordinates or vecor coordinates (x,y,z)
void	parse_coordinates(char *coordinates, t_vec3 *position)
{
	char	**xyz;

	xyz = ft_split(coordinates, ',');
	position->x = ft_atof(xyz[0]);
	position->y = ft_atof(xyz[1]);
	position->z = ft_atof(xyz[2]);
	free_parse_functions(xyz);
}

//helps parse triplets of colors (r,g,b)
void	parse_colors(char *coordinates, t_color *color)
{
	char	**xyz;

	xyz = ft_split(coordinates, ',');
	color->r = ft_atof(xyz[0]);
	color->g = ft_atof(xyz[1]);
	color->b = ft_atof(xyz[2]);
	free_parse_functions(xyz);
}
