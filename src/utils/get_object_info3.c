

#include "minirt.h"

float	*get_height(t_object *object)
{
	t_cylindre	*cylinder;

	if (object->type == CYLINDRE)
	{
		cylinder = (t_cylindre *)object->obj;
		return (&cylinder->hauteur);
	}
	return (NULL);
}

float	*get_radius(t_object *object)
{
	t_sphere	*sphere;
	t_cylindre	*cylinder;

	if (object->type == SPHERE)
	{
		sphere = (t_sphere *)object->obj;
		return (&sphere->rayon);
	}
	if (object->type == CYLINDRE)
	{
		cylinder = (t_cylindre *)object->obj;
		return (&cylinder->rayon);
	}
	return (NULL);
}
