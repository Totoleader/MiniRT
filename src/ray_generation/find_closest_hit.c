

#include "minirt.h"

//init helper to find_closest_hit()
static void	init_hit(t_hit *closest_hit, t_hit *hit)
{
	hit->t = 0;
	hit->obj = NULL;
	hit->hit_point = generate_vector(0, 0, 0);
	closest_hit->t = 0;
	closest_hit->obj = NULL;
	closest_hit->hit_point = generate_vector(0, 0, 0);
}

//updates the closest hit if closest hit has been found
static void	update_closest_hit(t_hit *closest_hit, t_hit hit)
{
	closest_hit->obj = hit.obj;
	closest_hit->t = hit.t;
	closest_hit->normal = hit.normal;
}

//finds if there is a hit with object being inspected
void	find_hit(t_vec3 d, t_object *object, t_hit *hit, t_vec3 origin)
{
	if (object->type == SPHERE)
		hit_sphere(d, object, hit, origin);
	else if (object->type == PLAN)
		hit_plane(d, object, hit, origin);
	else if (object->type == CYLINDRE)
		hit_cylinder(d, object, hit, origin);
}

//analyses every object in the schene and finds the closest hit with the ray
void	find_closest_hit(t_ray_info ray, t_hit *closest_hit, t_vec3 origin)
{
	t_hit		hit;
	t_list		*current;
	t_object	*object;

	init_hit(closest_hit, &hit);
	current = get_minirt()->objects;
	while (current)
	{
		object = current->content;
		find_hit(ray.d, object, &hit, origin);
		if (hit.obj && (ray.first_hit || hit.t < closest_hit->t))
		{
			update_closest_hit(closest_hit, hit);
			ray.first_hit = FALSE;
		}
		current = current->next;
	}
}

//main funciton of what a single ray has to do
t_shading	single_ray(t_ray_info ray, t_hit *closest_hit)
{
	t_shading	shade;

	find_closest_hit(ray, closest_hit, get_minirt()->camera.position);
	if (closest_hit->obj)
	{
		closest_hit->hit_point = vec_add(get_minirt()->camera.position,
				vec_scale(ray.d, closest_hit->t));
		closest_hit->hit_point = vec_add(closest_hit->hit_point,
				vec_scale(get_normal_vec(closest_hit),
					0.01));
		shade = shading(closest_hit);
		return (shade);
	}
	else
	{
		shade.color = no_color();
		shade.intensity = 0;
		return (shade);
	}
}
