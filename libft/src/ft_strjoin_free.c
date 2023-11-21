/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 14:00:20 by gle-roux         ###   ########.fr       */
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
char	*ft_strjoin_free(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*new_str;

	if (!str1 || !str2)
		return (NULL);
	len = 0;
	len = ft_strlen(str1) + ft_strlen(str2);
	new_str = (char *)ft_calloc((len + 1), sizeof(char));
	i = 0;
	j = 0;
	while (str1[i])
		new_str[j++] = str1[i++];
	i = 0;
	while (str2[i])
		new_str[j++] = str2[i++];
	new_str[j] = '\0';
	if (str1)
		str1 = ft_freenull(str1);
	if (str2)
		str2 = ft_freenull(str2);
	return (new_str);
}
