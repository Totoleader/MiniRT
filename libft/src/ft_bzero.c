/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:19:23 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 13:56:13 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include <string.h>
Description :
	The bzero() function writes n zeroed bytes to the string s.
	If n is zero, bzero() does nothing. The bzero() function fills the
	first n bytes of the object pointed to by dst with zero (NUL) bytes.
Declaration :
	void	ft_bzero(void *s, size_t n)
Parameters :
	s - The pointer from which to begin erasing data. / An existing
		object that you want to fill with zeroes.
	n - The number of bytes to erase.
Return value :
	-no value-
!!Same function as ft_memset with 0!!
*/
void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return ;
	ft_memset(s, 0, n);
}
