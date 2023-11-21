/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:02:19 by gle-roux          #+#    #+#             */
/*   Updated: 2023/01/26 11:20:05 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Library :
	#include <ctype.h>
Description :
	The isprint() function tests for any printing character, 
	including space (' '). The value of the argument must be representable as an 
	unsigned char or the value of EOF.
Declaration :
	int	ft_isprint(int c)
Parameters :
	c - The character to test.
Return value :
	The isprint() function returns zero if the character tests false and returns 
	non-zero if the character tests true.
*/
int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}
