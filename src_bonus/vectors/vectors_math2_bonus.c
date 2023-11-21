

#include "../../include/minirt_bonus.h"

/*
SCALE
Multiply a vector by a scalar and stores the result in res
*/
t_vec3	vec_scale(t_vec3 v, float scale)
{
	t_vec3	res;

	res.x = v.x * scale;
	res.y = v.y * scale;
	res.z = v.z * scale;
	return (res);
}

/*
DOT PRODUCT
Returns the dot product of two vectors.
It tells you what amount of one vector goes in the direction of another.
The result is not a vector, but a single number, a length of 
the “projection” multiplied by the length of the second vector.
*/
float	vec_dot(t_vec3 v1, t_vec3 v2)
{
	float	res;

	res = ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
	return (res);
}

/*
CROSS PRODUCT
The Cross Product a × b of two vectors is another vector
that is at right angles to both.
*/
t_vec3	vec_cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = (v1.y * v2.z) - (v1.z * v2.y);
	res.y = (v1.z * v2.x) - (v1.x * v2.z);
	res.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (res);
}

/*
NORMALIZE
Normalizing a vector means that an existing vector is converted to length 1.
The original direction of the vector is retained.
*/
t_vec3	vec_norm(t_vec3 v)
{
	float	len;
	float	ilen;
	t_vec3	res;

	len = vec_mag(v);
	ilen = 1.0 / len;
	res.x = v.x * ilen;
	res.y = v.y * ilen;
	res.z = v.z * ilen;
	return (res);
}
