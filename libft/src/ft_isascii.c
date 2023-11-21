/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:41:37 by gle-roux          #+#    #+#             */
/*   Updated: 2023/01/27 10:29:33 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Library :
	#include <ctype.h>
Description :
	The isascii() function tests for an ASCII character, which is any character 
	between 0 and octal 0177 inclusive.
Declaration :
	int	ft_isascii(int c)
Parameters :
	c - The character to test.
Return value :
	The isascii() function returns zero if the character tests false and returns 
	non-zero if the character tests true.
*/
int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}
