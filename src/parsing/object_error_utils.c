

#include "minirt.h"

int	nb_of_split(char **splits)
{
	int	split_count;

	split_count = 0;
	while (splits[split_count])
		split_count++;
	return (split_count);
}

int	is_all_digit_dot(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
	{
		i++;
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	while (str[i] && str[i + 1])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (FALSE);
		i++;
	}
	if (str[i] && str[i] != '\n' && !ft_isdigit(str[i]))
		return (FALSE);
	return (TRUE);
}
