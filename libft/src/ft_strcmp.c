/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 14:00:10 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include <string.h>
Description :
	The strcmp() function lexicographically compare the null-terminated strings
	s1 and s2.
Declaration :
	int	strcmp(const char *s1, const char *s2)
Parameters :
	s1 = the first string to compare;
	s2 = the second string to compare.
Return Value :
	The strcmp() function returns an integer greater than, equal
	to, or less than 0, according as the string s1 is greater than, equal to,
	or less than the string s2. The comparison is done using unsigned characters,
	so that `\200' is greater than `\0'.
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
