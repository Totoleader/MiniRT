/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 14:00:03 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	count_wd(char const *s, char c)
{
	int	i;
	int	len;
	int	counter;

	i = 0;
	len = ft_strlen(s);
	counter = 0;
	while (i < len)
	{
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c && c != '\0')
			i++;
		counter++;
	}
	return (counter);
}

static int	len_wd(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}

static const char	*get_next_wd(char const *s, char c, char *array)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		array[i] = s[i];
		i++;
	}
	while (s[i] && s[i] == c)
		i++;
	return (&s[i]);
}

/**
Library :
	#include "libft.h"
Description :
	Allocates (with malloc(3)) and returns an array of "fresh" strings (all
	ending with '\0', including the array itself) obtained by spliting s
	using the character c as a delimiter.
Declaration :
	char **ft_split(char const *s, char c)
* @param s the string to split
* @param c the delimiter character
* @return The array of "fresh" strings result of the split. 
	If the allocation fails, the function returns NULL.
	ex : ft_split ("*hello*fellow***students*", '*') returns the array ["hello, 
	"fellow", "students"]
*/
char	**ft_split(char const *s, char c)
{
	int		wd;
	char	**array;

	if (!s)
		return (0);
	while (*s == c && c != '\0')
		s++;
	array = ft_calloc((count_wd(s, c)) + 1, sizeof(char *));
	if (!array)
		return (0);
	wd = 0;
	while (wd < (count_wd(s, c) + wd))
	{
		array[wd] = ft_calloc((len_wd(s, c) + 1), sizeof(char));
		if (!array[wd])
		{
			free_tab(array);
			return (0);
		}
		s = get_next_wd(s, c, array[wd]);
		wd++;
	}
	return (array);
}
