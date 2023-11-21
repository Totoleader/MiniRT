

#include "../../include/minirt_bonus.h"

/*
ADDITION
Adds two vectors and stores the result in res
*/
t_vec3	vec_add(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

/*
SUBSTRACTION
Substracs two vectors and stores the result in res
*/
t_vec3	vec_subs(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}

/*
MULTIPLICATION
Multiply two vectors and stores the result in res
*/
t_vec3	vec_mult(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = v1.x * v2.x;
	res.y = v1.y * v2.y;
	res.z = v1.z * v2.z;
	return (res);
}

/*
LENGHT / MAGNITUDE
Returns the lenght of a vector
*/
float	vec_mag(t_vec3 v)
{
	float	len;

	len = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return (len);
}

/* 
UNIT
Returns the unit vector between two points represented by v1 and v2.
 */
t_vec3	vec_unit_vec(t_vec3 v1, t_vec3 v2)
{
	return (vec_norm(vec_subs(v1, v2)));
}
