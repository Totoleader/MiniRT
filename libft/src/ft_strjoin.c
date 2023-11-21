/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 14:00:22 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include "libft.h"
Description :
	Allocates (with malloc(3)) and returns a "fresh" string endling with '\0', 
	result of the concatenation of s1 and s2.
Declaration :
	char *ft_strjoin(char const *s1, char const *s2)
Parameters :
	s1 - the prefix string
	s2 - the suffix string
Return Value :
	The "fresh" string result of the concatenation of the 2 strings.
	If the allocation fails, the function returns NULL.
*/
char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*s3;
	size_t	len;

	len = (ft_strlen(s1) + ft_strlen(s2));
	s3 = ft_calloc((len + 1), sizeof(char));
	if (!s3)
		return (0);
	len = 0;
	while (s1[len])
	{
		s3[len] = s1[len];
		len++;
	}
	i = 0;
	while (s2[i])
	{
		s3[len + i] = s2[i];
		i++;
	}
	return (s3);
}
