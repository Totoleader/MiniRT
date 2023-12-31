/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_tab_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:59:11 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 13:56:38 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_char_tab_len(char **tab)
{
	int	i;

	i = 0;
	if (tab[i])
		while (tab[i])
			i++;
	return (i);
}
