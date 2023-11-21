/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 13:59:39 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Library :
	#include <string.h>
Description :
	The memcmp() function compares byte string s1 against byte string s2.  Both
	strings are assumed to be n bytes long.
Declaration :
	int memcmp(const void *s1, const void *s2, size_t n)
Parameters :
	s1 - string to compare
	s2 - other string to compare
	n - size of the strings
Return Value :
	The memcmp() function returns zero if the two strings are identical,
	otherwise returns the difference between the first two differing bytes
	(treated as unsigned char values, so that ‘\200’ is greater than ‘\0’, for
	example).  Zero-length strings are always identical.  This behavior is not
	required by C and portable code should only depend on the sign of the
	returned value.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (n > i)
	{
		if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			i++;
		else
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	}
	return (0);
}
