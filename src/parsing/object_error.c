

#include "minirt.h"

void	check_sphere_args(char **line, void *to_free)
{
	if (invalid_coords(line[1]) || invalid_value(line[2])
		|| invalid_coords_limited(line[3], 0.0f, 255.0f))
	{
		error(line, BAD_ARGS_SPHERE, to_free);
	}
}

void	check_cylinder_args(char **line, void *to_free)
{
	if (invalid_coords(line[1]) || invalid_coords_limited(line[2], -1.0f, 1.0f)
		|| invalid_value(line[3]) || invalid_value(line[4])
		|| invalid_coords_limited(line[5], 0.0f, 255.0f))
	{
		error(line, BAD_ARGS_CYLINDER, to_free);
	}
}

void	check_plane_args(char **line, void *to_free)
{
	if (invalid_coords(line[1]) || invalid_coords_limited(line[2], -1.0f, 1.0f)
		|| invalid_coords_limited(line[3], 0.0f, 255.0f))
	{
		error(line, BAD_ARGS_PLANE, to_free);
	}
}
