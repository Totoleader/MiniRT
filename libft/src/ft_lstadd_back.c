/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 13:57:55 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include "libft.h"
Description :
	Add the "new" element at the end of the list.
Declaration :
	void	ft_lstadd_back(t_list **lst, t_list *new)
Parameters :
	lst - the adress of a pointer to the first link of a list.
	new - the link to add at the end of the list.
Return Value :
	None.
-> operator :
	An arrow operator allows to access elements in Structures and Unions. It
	is used with a pointer variable pointing to a structure or union.
	The Arrow (->) operator exists to access the members of the structure or
	the unions using pointers.
The members of the t_list struct are:
		content	: The data contained in the node.
		void *	: Allows to store any kind of data.
		next	: The address of the next node, 
				  or NULL if the next node is the last one.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}
