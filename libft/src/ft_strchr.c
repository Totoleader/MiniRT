/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 14:00:08 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
Library :
	#include <string.h>
Description :
	The strchr() function locates the first occurrence of c (converted to a
	char) in the string pointed to by s. The terminating null character is
	considered to be part of the string; therefore if c is `\0', the
	functions locate the terminating `\0'.
Declaration :
	char *strchr(const char *s, int c)
* @param s The string in which to checks for the occurence of c.
* @param c The character to check the occurence of.
* @return The functions strchr() return a pointer to the located character,
	or NULL if the character does not appear in the string
*/
char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}
