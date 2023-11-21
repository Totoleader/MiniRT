/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:47:28 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 13:59:46 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include <string.h>
Description :
	The C library function void *memset(void *b, int c, size_t len) copies
	the character c (an unsigned char) to the first n characters of the
	string pointed to, by the argument b.
Declaration :
	void *memset(void *b, int c, size_t len)
Parameters :
	b − This is a pointer to the block of memory to fill.
	c − This is the value to be set. The value is passed as an int,
		but the function fills the block of memory using the unsigned char
		conversion of this value.
	len − This is the number of bytes to be set to the value.
Return Value :
	This function returns a pointer to the memory area str.
*/
void	*ft_memset(void *b, int c, size_t len)
{
	if (!b)
		return (0);
	while (len-- > 0)
		((unsigned char *)b)[len] = c;
	return (b);
}
