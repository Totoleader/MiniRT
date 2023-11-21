

#include "minirt.h"

static void	atof_init(char *str, int *i, int *is_negative)
{
	*i = 0;
	*is_negative = 0;
	while (str[*i] == ' ' || (str[*i] == '\t') || (str[*i] == '\n')
		|| (str[*i] == '\v') || (str[*i] == '\f') || (str[*i] == '\r'))
		(*i)++;
	if (str[*i] == '+')
		(*i)++;
	else if (str[*i] == '-')
		*is_negative = ++(*i);
}

//atoi with floats
float	ft_atof(char *str)
{
	int		i;
	int		is_negative;
	float	resultat;

	if (!str)
		return (0);
	resultat = 0;
	atof_init(str, &i, &is_negative);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		resultat = (resultat * 10.0f) + (str[i++] - 48);
	if (str[i] && str[i] != '.' && str[i] != '\n')
		return (-1);
	if (str[i++] == '.')
	{
		str = &str[i];
		i = 0;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			resultat = resultat * 10.0f + (str[i++] - 48);
		while (i--)
			resultat /= 10.0f;
	}
	if (is_negative)
		resultat *= -1.0f;
	return (resultat);
}

//atoi with floats
double	ft_atod(char *str)
{
	int		i;
	int		is_negative;
	double	resultat;

	if (!str)
		return (0);
	resultat = 0;
	atof_init(str, &i, &is_negative);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		resultat = (resultat * 10.0f) + (str[i++] - 48);
	if (str[i] && str[i] != '.' && str[i] != '\n')
		return (-2);
	if (str[i++] == '.')
	{
		str = &str[i];
		i = 0;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			resultat = (resultat * 10.0f) + (str[i++] - 48);
		while (i--)
			resultat /= 10.0f;
	}
	if (is_negative)
		resultat *= -1.0f;
	return (resultat);
}
