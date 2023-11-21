

#include "minirt.h"

void	fill_sphere_info(t_object *object, char **line)
{
	object->type = SPHERE;
	object->obj = ft_calloc(1, sizeof(t_sphere));
	parse_sphere(line, object);
}

void	fill_plane_info(t_object *object, char **line)
{
	object->type = PLAN;
	object->obj = ft_calloc(1, sizeof(t_plan));
	parse_plane(line, object);
}

void	fill_cylinder_info(t_object *object, char **line)
{
	object->type = CYLINDRE;
	object->obj = ft_calloc(1, sizeof(t_cylindre));
	parse_cylinder(line, object);
}
