/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 14:00:43 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include "libft.h"
Description :
	Allocates (with malloc(3)) and returns a “fresh” substring from the string
	given as argument. The substring begins at indexstart and is of size len.
Declaration :
	char *ft_substr(char const *s, unsigned int start, size_t len)
Parameters :
	s - The string from which create the substring.
	start - The start index of the substring.
	len - The size of the substring.
Return Value :
	The new substring
	NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	size_t	len_s;
	char	*sub_s;
	size_t	len_sub_s;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (len_s < start)
		return (sub_s = ft_calloc(1, sizeof(char)));
	if ((start < len_s) && (start + len <= len_s))
		len_sub_s = len;
	else
		len_sub_s = len_s - start;
	sub_s = ft_calloc((len_sub_s + 1), sizeof(char));
	if (!sub_s)
		return (NULL);
	i = 0;
	while (s && len_sub_s--)
		sub_s[i++] = s[start++];
	sub_s[i] = '\0';
	return (sub_s);
}
