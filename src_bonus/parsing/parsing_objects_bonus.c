

#include "../../include/minirt_bonus.h"

t_material	*get_material(char *line)
{
	if (!line)
		return (&get_minirt()->material[NO_MAT2]);
	if (!ft_strncmp(line, "mirror", 7))
		return (&get_minirt()->material[NO_MAT]);
	else if (!ft_strncmp(line, "moon", 5))
		return (&get_minirt()->material[MOON]);
	else if (!ft_strncmp(line, "earth", 6))
		return (&get_minirt()->material[EARTH]);
	else if (!ft_strncmp(line, "wood", 6))
		return (&get_minirt()->material[WOOD]);
	else if (!ft_strncmp(line, "sun", 4))
		return (&get_minirt()->material[SUN]);
	else if (!ft_strncmp(line, "damier", 7))
		return (&get_minirt()->material[DAMIER]);
	else
		return (&get_minirt()->material[NO_MAT2]);
}

//parses line input to the sphere struct
void	parse_sphere(char **line, t_object *object)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)object->obj;
	check_error(line, SPHERE, object);
	parse_coordinates(line[1], &sphere->position);
	sphere->rayon = ft_atof(line[2]) / 2;
	parse_colors(line[3], &sphere->color);
	sphere->material = get_material(line[4]);
}

//parses line input to the cylinder struct
void	parse_cylinder(char **line, t_object *object)
{
	t_cylindre	*cylindre;

	cylindre = (t_cylindre *)object->obj;
	check_error(line, CYLINDRE, object);
	parse_coordinates(line[1], &cylindre->position);
	parse_coordinates(line[2], &cylindre->direction);
	cylindre->rayon = ft_atof(line[3]) / 2;
	cylindre->hauteur = ft_atof(line[4]);
	parse_colors(line[5], &cylindre->color);
	cylindre->material = get_material(line[6]);
}

//parses line input to the plane struct
void	parse_plane(char **line, t_object *object)
{
	t_plan	*plan;

	plan = (t_plan *)object->obj;
	check_error(line, PLAN, object);
	parse_coordinates(line[1], &plan->position);
	parse_coordinates(line[2], &plan->direction);
	parse_colors(line[3], &plan->color);
	plan->material = get_material(line[4]);
}

void	parse_cone(char **line, t_object *object)
{
	t_cone	*cone;

	cone = (t_cone *)object->obj;
	check_error(line, CONE, object);
	parse_coordinates(line[1], &cone->position);
	parse_coordinates(line[2], &cone->direction);
	cone->angle = ft_atof(line[3]) * (M_PI / 180.0f);
	cone->hauteur = ft_atof(line[4]);
	parse_colors(line[5], &cone->color);
	cone->material = get_material(line[6]);
}
