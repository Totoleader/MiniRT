

#include "minirt.h"

//redirects to the right kind of object to check
void	check_invalid_arg(char **line, int type, void *to_free)
{
	if (type == SPHERE)
		check_sphere_args(line, to_free);
	else if (type == CYLINDRE)
		check_cylinder_args(line, to_free);
	else if (type == PLAN)
		check_plane_args(line, to_free);
	else if (type == AMBIANT_LIGHT)
		check_amb_light_args(line, to_free);
	else if (type == LIGHT)
		check_light_args(line, to_free);
	else if (type == CAMERA)
		check_camera_args(line, to_free);
}

//go search for input error
void	check_error(char **line, int type, void *to_free)
{
	check_bad_arg_count(line, type, to_free);
	check_invalid_arg(line, type, to_free);
}

char	*get_error_message2(int error_code)
{
	if (error_code == BAD_ARGS_CYLINDER)
		return ("Error: Invalid argument found in cylinder");
	else if (error_code == BAD_ARGS_LIGHT)
		return ("Error: Invalid argument found in light");
	else if (error_code == BAD_ARGS_PLANE)
		return ("Error: Invalid argument found in plane");
	else if (error_code == BAD_ARGS_SPHERE)
		return ("Error: Invalid argument found in sphere");
	else
		return ("Obscur error.");
}

//gets the right error message for the specified error code.
char	*get_error_message(int error_code)
{
	if (error_code == INVALID_OBJECT)
		return ("Error: Unknown type of object");
	else if (error_code == DUPLICATE_OBJECT)
		return ("Error: Duplicate object (camera or light or ambiant light)");
	else if (error_code == BAD_ARG_COUNT_AMB_LIGHT)
		return ("Error: Not the right amount of arguments for ambiant light");
	else if (error_code == BAD_ARG_COUNT_CAMERA)
		return ("Error: Not the right amount of arguments for camera");
	else if (error_code == BAD_ARG_COUNT_CYLINDER)
		return ("Error: Not the right amount of arguments for cylinder");
	else if (error_code == BAD_ARG_COUNT_LIGHT)
		return ("Error: Not the right amount of arguments for light");
	else if (error_code == BAD_ARG_COUNT_PLANE)
		return ("Error: Not the right amount of arguments for plane");
	else if (error_code == BAD_ARG_COUNT_SPHERE)
		return ("Error: Not the right amount of arguments for sphere");
	else if (error_code == BAD_ARGS_AMB_LIGHT)
		return ("Error: Invalid argument found in ambiant light");
	else if (error_code == BAD_ARGS_CAMERA)
		return ("Error: Invalid argument found in camera");
	else
		return (get_error_message2(error_code));
}

//last thing that is called in case of an error
//to free might be null if not needed
//**EXITS THE PROGRAM**
void	error(char **line, int error_code, void *to_free)
{
	free_minirt();
	if (line)
		free_splitted_line(line);
	if (to_free)
		free(to_free);
	ft_putstr_fd(get_error_message(error_code), STDERR_FILENO);
	exit(0);
}
