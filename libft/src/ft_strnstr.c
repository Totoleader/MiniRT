/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 14:00:36 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include <string.h>
Description :
	The strnstr() function locates the first occurrence of the null-terminated
	string needle in the string haystack, where not more than len characters
	are searched. Characters that appear after a ‘\0’ character are not
	searched.
Declaration :
	char *strnstr(const char *haystack, const char *needle, size_t len)
Parameters :
	haystack - The string in which to check for the occurence
	of the substring.
	needle - The substring to check the occurence of.
	len - The number of bytes to check in haystack.
Return Value :
	If needle is an empty string, haystack is returned; if needle occurs
	nowhere in haystack, NULL is returned; otherwise a pointer to the first
	character of the first occurrence of needle is returned.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	if (!haystack || !needle)
		return (0);
	h = 0;
	if ((needle[0] == '\0') || (!haystack && len == 0))
		return ((char *)haystack);
	while (haystack[h] != '\0')
	{
		n = 0;
		while ((haystack[h + n] == needle[n]) && (len > (h + n)))
		{
			if ((needle[n + 1] == '\0'))
				return (&((char *)haystack)[h]);
			n++;
		}
		h++;
	}
	return (0);
}
