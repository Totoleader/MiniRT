/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 14:00:15 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include <string.h>
Description :
	The strdup() function allocates sufficient memory for a copy of the string
	s1, does the copy, and returns a pointer to it. The pointer may
	subsequently be used as an argument to the function free(3).
	If insufficient memory is available, NULL is returned.
Declaration :
	char *strdup(const char *s1)
Parameters :
	s1 - The string to duplicate.
Return Value :
	The strdup() function returns the pointer to the copy of s1.
*/
char	*ft_strdup(const char *s1)
{
	char	*dest;

	if (!s1)
		return (0);
	dest = ft_calloc(sizeof(char), (ft_strlen(s1) + 1));
	if (!dest)
		return (0);
	return (ft_strcpy(dest, s1));
}
