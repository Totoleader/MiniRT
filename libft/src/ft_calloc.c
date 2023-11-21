/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 13:56:35 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include <stdlib.h>
Description :
	The calloc() function contiguously allocates enough space for count objects
	that are size bytes of memory each and returns a pointer to the allocated
	memory. The allocated memory is filled with bytes of value zero.
Declaration :
	void *calloc(size_t count, size_t size)
Parameters :
	count - The count of objects to allocate.
	size - The size of bytes in each object.
Return Value :
	If successful, calloc() function return a pointer to allocated memory.
	If there is an error, they return a NULL pointer and set errno to ENOMEM.

***Free function : void free(void *ptr)
	The free() function frees allocations that were created via the preceding
	allocation functions.  The free() function deallocates the memory
	allocation pointed to by ptr. If ptr is a NULL pointer, no operation
	is performed.
	The free() function does not return a value.
*/
void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*dest;

	dest = (void *)malloc(size * count);
	if (!dest)
		return (0);
	i = 0;
	while (i < (count * size))
		dest[i++] = 0;
	return (dest);
}
