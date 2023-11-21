/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 13:56:11 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include <stdlib.h>
Description :
	The atol() function converts the initial portion of the string pointed to
		by str to long integer representation.
Declaration :
	long atol(const char *str)
Parameters :
	str - The string to convert to long integer.
Return Value :
	The atol() function returns its converted int representation.
*/
long	ft_atol(const char *str)
{
	long	i;
	long	neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			neg *= -1;
		i++;
	}
	while (str[i] == '0' && str[i + 1] != '\0')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * neg);
}
