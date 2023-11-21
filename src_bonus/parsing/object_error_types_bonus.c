

#include "../../include/minirt_bonus.h"

int	invalid_value(char *coords)
{
	if (!is_all_digit_dot(coords))
		return (TRUE);
	else if (ft_atod(coords) - ft_atof(coords) > 0.0001)
		return (TRUE);
	else
		return (FALSE);
}

int	invalid_value_limited(char *coords, float min, float max)
{
	float	value;

	if (invalid_value(coords))
	{
		return (TRUE);
	}
	value = ft_atof(coords);
	if (value > max || value < min)
	{
		return (TRUE);
	}
	return (FALSE);
}

int	invalid_coords(char *coords)
{
	char	**split;

	split = ft_split(coords, ',');
	if (nb_of_split(split) != 3)
	{
		free_splitted_line(split);
		return (TRUE);
	}
	else if (invalid_value(split[0])
		|| invalid_value(split[1])
		|| invalid_value(split[2]))
	{
		free_splitted_line(split);
		return (TRUE);
	}
	free_splitted_line(split);
	return (FALSE);
}

int	invalid_coords_limited(char *coords, float min, float max)
{
	char	**split;

	split = ft_split(coords, ',');
	if (nb_of_split(split) != 3)
	{
		free_splitted_line(split);
		return (TRUE);
	}
	else if (invalid_value_limited(split[0], min, max)
		|| invalid_value_limited(split[1], min, max)
		|| invalid_value_limited(split[2], min, max))
	{
		free_splitted_line(split);
		return (TRUE);
	}
	free_splitted_line(split);
	return (FALSE);
}
