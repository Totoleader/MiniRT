/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 14:00:41 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*Library :
	#include "libft.h"
Description :
	Allocates (with malloc(3)) and returns a copy of the string given as
	argument (s1) without characters specified in 'set' at the beginning and at
	the end of the string.
Declaration :
	char *ft_strtrim(char const *s1, char const *set)
Parameters :
	s1 - the string to be trimed
	set - characters to trim
Return Value :
	s1 trimmed.
	The function returns NULL is the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		start;
	char	*s_trim;

	if (!s1)
		return (0);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end && ft_strchr(set, s1[end]))
		end--;
	s_trim = ft_substr(s1, start, end - start + 1);
	return (s_trim);
}
