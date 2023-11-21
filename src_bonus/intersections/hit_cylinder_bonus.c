

#include "../../include/minirt_bonus.h"

/*
Calculates the normal vector at the intersection point.
Surface normal vector calcul :
	// n = nrm(P-C-V*m)
	// n = nrm( P-C - (1+k*k)*V*m )
*/
t_vec3	calc_normal_cylinder(t_qdt q, t_hit *hit, t_cylindre *cylinder)
{
	t_vec3	n;
	t_vec3	disp;
	t_vec3	hit_point;
	float	proj;

	hit_point = vec_add(q.origin, vec_scale(q.d, hit->t));
	disp = vec_subs(hit_point, cylinder->position);
	proj = vec_dot(disp, vec_norm(cylinder->direction));
	n = vec_norm(vec_subs(disp, vec_scale(vec_norm(cylinder->direction), \
		proj)));
	return (n);
}

/* 
Handles the logic of whether the ray hits the cone or not
and updates the hit structure accordingly.
 */
static void	hit_cylinder_norm(t_qdt q, t_hit *hit, t_cylindre *cyl, \
	t_object *packed_cylinder)
{
	if (q.t < 0.00001 || fabs(q.m) > cyl->hauteur / 2)
	{
		q.t = (-q.half_b + sqrtf(q.discriminant)) / q.a;
		q.m = vec_dot(q.d, vec_norm(cyl->direction)) * q.t + \
			vec_dot(q.disp, vec_norm(cyl->direction));
		if (q.t < 0.00001 || fabs(q.m) > cyl->hauteur / 2)
		{
			hit->obj = NULL;
			hit->t = ERROR;
			return ;
		}
		else
		{
			hit->obj = packed_cylinder;
			hit->t = q.t;
			hit->normal = calc_normal_cylinder(q, hit, cyl);
		}
	}
	else
	{
		hit->obj = packed_cylinder;
		hit->t = q.t;
		hit->normal = calc_normal_cylinder(q, hit, cyl);
	}
}

/*
Calculate ray-cylinder intersections.
It sets up the quadratic equation parameters for the cylinder
and uses the discriminant to determine if there is an intersection.

Equation :
	a = D|D - (D|V)^2
	b/2 = D|X - (D|V)*(X|V)
	c = X|X - (X|V)^2 - r*r
	d = b² - a * c
	t = (-b - √d) / a; OUTSIDE
	t = (-b + √d) / a; INSIDE
	m = D|V*t + X|V
*/
void	hit_cylinder(t_vec3 d, t_object *packed_cylinder, \
	t_hit *hit, t_vec3 origin)
{
	t_qdt		q;
	t_cylindre	*cyl;

	cyl = (t_cylindre *)packed_cylinder->obj;
	q.disp = vec_subs(origin, cyl->position);
	q.a = vec_dot(d, d) - pow(vec_dot(d, vec_norm(cyl->direction)), 2);
	q.half_b = vec_dot(d, q.disp) - vec_dot(d, vec_norm(cyl->direction)) \
		* vec_dot(q.disp, vec_norm(cyl->direction));
	q.c = vec_dot(q.disp, q.disp) - pow(vec_dot(q.disp, \
		vec_norm(cyl->direction)), 2) - pow(cyl->rayon, 2);
	q.discriminant = pow(q.half_b, 2) - (q.a * q.c);
	if (q.discriminant < 0.00001)
	{
		hit->obj = NULL;
		hit->t = ERROR;
		return ;
	}
	q.t = (-q.half_b - sqrtf(q.discriminant)) / q.a;
	q.m = vec_dot(d, vec_norm(cyl->direction)) * q.t + vec_dot(q.disp, \
		vec_norm(cyl->direction));
	q.origin = origin;
	q.d = d;
	hit_cylinder_norm(q, hit, cyl, packed_cylinder);
}
