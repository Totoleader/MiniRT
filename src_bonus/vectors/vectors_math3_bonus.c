

#include "../../include/minirt_bonus.h"

/*
COPY
Returns a copy of a vector passed in argument.
*/
t_vec3	vec_copy(t_vec3 v)
{
	t_vec3	copy;

	copy.x = v.x;
	copy.y = v.y;
	copy.z = v.z;
	return (copy);
}

/*
RESET
Sets all components of a vector to 0 and returns it.
*/
void	vec_reset(t_vec3 *v)
{
	v->x = 0;
	v->y = 0;
	v->z = 0;
}

/* 
GENERATE
Creates and returns a 3D vector with the specified x, y, and z components.
 */
t_vec3	generate_vector(float x, float y, float z)
{
	t_vec3	null_vector;

	null_vector.x = x;
	null_vector.y = y;
	null_vector.z = z;
	return (null_vector);
}

/* 
UP GUIDE
Returns a vector representing the "up" direction
in a standard coordinate system.
 */
t_vec3	up_guide(void)
{
	t_vec3	up_guide;

	up_guide.x = 0.0f;
	up_guide.y = 1.0f;
	up_guide.z = 0.0f;
	return (up_guide);
}
