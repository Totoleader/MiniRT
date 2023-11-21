

#include "../../include/minirt_bonus.h"

//readability helper in parsing.c/new_struct()
int	is_object(char *type)
{
	if (!ft_strncmp(type, "cy", 3) || !ft_strncmp(type, "sp", 3)
		|| !ft_strncmp(type, "pl", 3) || !ft_strncmp(type, "co", 3))
		return (TRUE);
	return (FALSE);
}

//readability helper in parsing.c/new_struct()
int	is_scene_info(char *type)
{
	if (!ft_strncmp(type, "A", 2) || !ft_strncmp(type, "L", 2)
		|| !ft_strncmp(type, "C", 2))
		return (TRUE);
	return (FALSE);
}

//free helper in parsing.c/new_struct()
void	free_splitted_line(char **line)
{
	int	i;

	if (!line)
		return ;
	i = 0;
	while (line[i])
		free(line[i++]);
	free(line);
}

//funciton used as a helper to "trim_gnl()" //cbp**
static char	*trim_gnl_helper(char *str, char *output)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!((str[i] == ' ' || str[i] == '	') && (str[i - 1] == ' ' || (str[i
							- 1] == '	'))) && str[i] != '\n')
		{
			if (str[i] == '	')
				str[i] = ' ';
			output[count++] = str[i];
		}
		i++;
	}
	str = ft_freenull(str);
	return (output);
}

//Helper to parse(). Cleans up output of get_next_line()
char	*trim_gnl(char *str)
{
	int		i;
	int		count;
	char	*output;

	if (!str)
		return (NULL);
	i = 1;
	count = 1;
	while (str[i])
	{
		if (!((str[i] == ' ' || str[i] == '	') && (str[i - 1] == ' ' || (str[i
							- 1] == '	'))) && str[i] != '\n')
			count++;
		i++;
	}
	output = ft_calloc(sizeof(char), count + 1);
	return (trim_gnl_helper(str, output));
}
