

#include "minirt.h"

/*
Calculates the intersection of a ray defined by its direction d
and origin with a plane defined by its position and normal
direction [plane->position and plane->direction].

Equation :
	       
	     ___a___
	    |       |
	     c - p.n
	t = ---------
	       d.n
	      |___|
			b

*/
void	hit_plane(t_vec3 d, t_object *packed_plane, t_hit *hit, t_vec3 origin)
{
	float	a;
	float	b;
	float	t;
	t_plan	*plane;

	plane = (t_plan *)packed_plane->obj;
	a = vec_dot(vec_subs(plane->position, origin), vec_norm(plane->direction));
	b = vec_dot(d, vec_norm(plane->direction));
	if (b < 0.0001)
		hit->obj = NULL;
	t = a / b;
	if (t < 0.0001)
		hit->obj = NULL;
	else
	{
		hit->obj = packed_plane;
		hit->t = t;
	}
}
