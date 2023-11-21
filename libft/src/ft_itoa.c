/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 13:56:49 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	len_number(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static int	absolute_value(int nb)
{
	if (nb < 0)
		return (nb *= -1);
	return (nb);
}

/*
Library :
	#include "libft.h"
Description :
	Allocate (with malloc(3)) and returns a "fresh" string ending with '\0'
	representing the integer n given as argument. Negative numbers must be 
	supported.
Declaration :
	char *ft_itoa(int n)
Parameters :
	n - the integer to be transformed into a string
Return Value :
	The string representing the integer passed as argument.
	If the allocation fails, the function returns NULL.
*/
char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	len = len_number(n);
	s = ft_calloc(len + 1, sizeof(char));
	if (!s)
		return (0);
	s[len--] = '\0';
	if (n < 0)
		s[0] = '-';
	else if (n == 0)
		s[0] = '0';
	while (n != 0)
	{
		s[len--] = absolute_value(n % 10) + 48;
		n = n / 10;
	}
	return (s);
}
