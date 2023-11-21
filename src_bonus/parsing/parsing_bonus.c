

#include "../../include/minirt_bonus.h"

//Directs to the right parsing function depending on
//the kind of objecti
void	new_obj(char **line)
{
	t_object	*object;

	object = ft_calloc(1, sizeof(t_object));
	if (!ft_strncmp(line[0], "sp", 3))
	{
		fill_sphere_info(object, line);
	}
	else if (!ft_strncmp(line[0], "pl", 3))
	{
		fill_plane_info(object, line);
	}
	else if (!ft_strncmp(line[0], "cy", 3))
	{
		fill_cylinder_info(object, line);
	}
	else if (!ft_strncmp(line[0], "co", 3))
	{
		fill_cone_info(object, line);
	}
	ft_lstadd_back(&get_minirt()->objects, ft_lstnew(object));
}

//Directs to the right parsing function depending on the
//kind of scene info object
void	new_scene_info(char **line)
{
	static int	nb_camera = 0;
	static int	nb_amb_light = 0;

	if (!ft_strncmp(line[0], "A", 2) && nb_amb_light == 0)
	{
		parse_ambiant_light(line);
		nb_amb_light = 1;
	}
	else if (!ft_strncmp(line[0], "C", 2) && nb_camera == 0)
	{
		parse_camera(line);
		nb_camera = 1;
	}
	else if (!ft_strncmp(line[0], "L", 2))
	{
		parse_light(line);
	}
	else
	{
		error(line, DUPLICATE_OBJECT, NULL);
	}
}

//redirects to the right parsing functions
void	new_struct(char **line)
{
	if (is_object(line[0]))
	{
		new_obj(line);
	}
	else if (is_scene_info(line[0]))
	{
		new_scene_info(line);
	}
	else if (!ft_strncmp(line[0], "#", 1))
	{
	}
	else
	{
		error(line, INVALID_OBJECT, NULL);
	}
	free_splitted_line(line);
}

//entry parsing function, reads lines with gnl
//and calls the struct constructor
void	parse(int fd)
{
	char	*next_line;
	char	**splitted_line;

	next_line = trim_gnl(get_next_line(fd));
	while (next_line)
	{
		if (next_line[0])
		{
			splitted_line = ft_split(next_line, ' ');
			new_struct(splitted_line);
		}
		if (next_line)
			next_line = ft_freenull(next_line);
		next_line = trim_gnl(get_next_line(fd));
	}
	close(fd);
}
