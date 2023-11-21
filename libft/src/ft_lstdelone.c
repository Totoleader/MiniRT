/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/08/11 13:55:23 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include "libft.h"
Description :
	Free the memory of the element passed as argument by using the 'del'
	function and then with free(3). The memory of 'next' must not be free.
Declaration :
	void ft_lstdelone(t_list *lst, void (*del)(void *))
Parameters :
	lst - The element to free
	del - The address of the function to delete the content of the element.
Return Value :
	None.
*/
void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}
