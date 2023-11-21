/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 14:00:24 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include <string.h>
Description :
	strlcat() appends string src to the end of dst.  It will append at most 
	dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless 
	dstsize is 0 or the original dst string was longer than dstsize (in practice 
	this should not happen as it means that either dstsize is incorrect or that 
	dst is not a proper string).
Declaration :
	size_t	strlcat(char *dst, const char *src, size_t dstsize)
Parameters :
	dst - The destiny string in which to concatenate.
	src - The source string to concatenate.
	dstsize - The total number of bytes in destiny.
Return Value :
	the strlcat() function returns the length of the string it tried to create.
	Return value = dst + src + '\0'
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;

	if (!src)
		return (0);
	if (!dst)
		return (ft_strlen(src));
	len_dst = ft_strlen(dst);
	if (dstsize < len_dst)
		return (dstsize + ft_strlen(src));
	i = 0;
	if ((dstsize > 0) && (dstsize - 1 > len_dst))
	{
		while ((src[i] != '\0') && (dstsize - 1 > len_dst + i))
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		dst[len_dst + i] = '\0';
	}
	return (len_dst + ft_strlen(src));
}
