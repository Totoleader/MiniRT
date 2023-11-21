

#include "../../include/minirt_bonus.h"

void	check_amb_light_args(char **line, void *to_free)
{
	if (invalid_value_limited(line[1], 0.0f, 1.0f)
		|| invalid_coords_limited(line[2], 0.0f, 255.0f))
	{
		error(line, BAD_ARGS_AMB_LIGHT, to_free);
	}
}

void	check_light_args(char **line, void *to_free)
{
	if (invalid_coords(line[1]) || invalid_value_limited(line[2], 0.0f, 1.0f)
		|| invalid_coords_limited(line[3], 0.0f, 255.0f))
	{
		error(line, BAD_ARGS_LIGHT, to_free);
	}
}

void	check_camera_args(char **line, void *to_free)
{
	if (invalid_coords(line[1]) || invalid_coords_limited(line[2], -1.0f, 1.0f)
		|| invalid_value_limited(line[3], 0.0f, 180.0f))
	{
		error(line, BAD_ARGS_CAMERA, to_free);
	}
}
