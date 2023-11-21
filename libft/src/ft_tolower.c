/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/01/26 11:20:38 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Library :
	#include <ctype.h>
Description :
	The tolower() function converts an upper-case letter to the corresponding
	lower-case letter.  The argument must be representable as an unsigned
	char or the value of EOF.
Declaration :
	int	tolower(int c)
Parameters :
	c - The character to convert.
Return Value :
	If the argument is a upper-case letter, the tolower() function returns the 
	corresponding lower-case letter if there is one; otherwise, the argument is 
	returned unchanged.
*/
int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}
