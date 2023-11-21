/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:23:06 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 13:56:45 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include <ctype.h>
Description :
	The isalnum() function tests for any character for which isalpha(3) or 
	isdigit(3) is true. The value of the argument must be representable as an 
	unsigned char or the value of EOF.
Declaration :
	int	ft_isalnum(int c)
Parameters :
	c - The character to test.
Return value :
	The isalnum() function returns zero if the character tests false and returns 
	non-zero if the character tests true.
*/
int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) == 1) || (ft_isdigit(c) == 1))
		return (1);
	return (0);
}
