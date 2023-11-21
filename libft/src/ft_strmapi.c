/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 14:00:31 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include "libft.h"
Description :
	Applies the function f to each character of the string given as argument to
	create a "fresh" new string (with malloc(3)) resulting from the successive
	application of f.
Declaration :
	char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
Parameters :
	s - the string to map
	f - the function to apply to each character of s and its index
Return Value :
	the "fresh" string created from the successive applications of f.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	if (!s || !f)
		return ((dest = ft_calloc(1, sizeof(char))));
	dest = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (dest == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
