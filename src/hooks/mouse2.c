

#include "minirt.h"

static void	update(t_hit *closest_hit, t_hit hit)
{
	object_selected(hit);
	update_closest_hit_mouse(closest_hit, hit);
}

void	find_closest_object(t_ray_info *ray, t_hit *closest_hit)
{
	t_hit		hit;
	t_list		*current;
	t_object	*object;

	init_hit_mouse(closest_hit, &hit);
	current = get_minirt()->objects;
	while (current)
	{
		object = current->content;
		if (object->type == SPHERE)
			hit_sphere(ray->d, object, &hit, get_minirt()->camera.position);
		else if (object->type == PLAN)
			hit_plane(ray->d, object, &hit, get_minirt()->camera.position);
		else if (object->type == CYLINDRE)
			hit_cylinder(ray->d, object, \
			&hit, get_minirt()->camera.position);
		if (hit.obj && (first_hit_mouse(TRUE) || hit.t < closest_hit->t))
			update(closest_hit, hit);
		current = current->next;
	}
	first_hit_mouse(FALSE);
}
