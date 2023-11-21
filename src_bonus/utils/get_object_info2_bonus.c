

#include "../../include/minirt_bonus.h"

t_vec3	get_plane_direction(t_object *object)
{
	t_plan	*plane;

	if (object->type == PLAN)
	{
		plane = (t_plan *)object->obj;
		return (plane->direction);
	}
	return (generate_vector(0, 0, 0));
}

t_vec3	get_cylinder_direction(t_object *object)
{
	t_cylindre	*cyl;

	if (object->type == CYLINDRE)
	{
		cyl = (t_cylindre *)object->obj;
		return (cyl->direction);
	}
	return (generate_vector(0, 0, 0));
}

t_vec3	get_cone_direction(t_object *object)
{
	t_cone	*cone;

	if (object->type == CONE)
	{
		cone = (t_cone *)object->obj;
		return (cone->direction);
	}
	return (generate_vector(0, 0, 0));
}

t_material	*get_obj_material(t_object *obj)
{
	if (obj->type == SPHERE)
	{
		return (((t_sphere *)obj->obj)->material);
	}
	else if (obj->type == PLAN)
	{
		return (((t_plan *)obj->obj)->material);
	}
	else if (obj->type == CYLINDRE)
	{
		return (((t_cylindre *)obj->obj)->material);
	}
	else if (obj->type == CONE)
	{
		return (((t_cone *)obj->obj)->material);
	}
	else
		return (NULL);
}
