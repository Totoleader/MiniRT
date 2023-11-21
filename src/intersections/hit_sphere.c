

#include "minirt.h"

/* 
Handles the logic of whether the ray hits the sphere (inside or outside)
or not and updates the hit structure accordingly.
 */
static void	hit_sphere_norm(t_qdt q, t_hit *hit, t_object *packed_sphere)
{
	q.t = (-q.b - sqrtf(q.discriminant)) / (2.0f * q.a);
	if (q.t < 0.00001)
	{
		q.t = (-q.b + sqrtf(q.discriminant)) / (2.0f * q.a);
		if (q.t < 0.00001)
		{
			hit->t = 0.0f;
			hit->obj = NULL;
		}
		else
		{
			hit->obj = packed_sphere;
			hit->t = q.t;
		}
	}
	else
	{
		hit->obj = packed_sphere;
		hit->t = q.t;
	}
}

/*
calculates ray-cylinder intersections.
It sets up the quadratic equation parameters for the cylinder
and uses the discriminant to determine if there is an intersection.

Equation :
	 (d.d)t² + 2d.(p - c)t + (p - c)(p - c) - r² = 0
	|______|  |___________| |___________________|
		a			b				c
*/
void	hit_sphere(t_vec3 d, t_object *packed_sphere, t_hit *hit, t_vec3 origin)
{
	t_qdt		q;
	t_sphere	*sphere;

	sphere = packed_sphere->obj;
	q.disp = vec_subs(origin, sphere->position);
	q.a = vec_dot(d, d);
	q.b = vec_dot(vec_scale(d, 2.0f), q.disp);
	q.c = vec_dot(q.disp, q.disp) - pow(sphere->rayon, 2);
	q.discriminant = pow(q.b, 2) - (4.0f * q.a * q.c);
	if (q.discriminant < 0.0f)
	{
		hit->obj = NULL;
		hit->t = 0.0f;
	}
	else
		hit_sphere_norm(q, hit, packed_sphere);
}
