/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/08/01 14:59:46 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include "libft.h"
Description :
	Iterates on the list 'lst' and applies the function 'f' to the content of
	each element. Creates a new list resulting from the successive applications
	of 'f'. The 'del' function is there to destroy the content of an element
	if necessary.
Declaration :
	t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
Parameters :
	lst - The address of the pointer to an element. f: The address of the
	function to apply.
	del - The address of the function to delete the content of an element.
Return Value :
	The 'new' list.
	NULL if the allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	void	*tmp;

	if (!lst || !f)
		return (0);
	new_lst = 0;
	while (lst != NULL)
	{
		tmp = (*f)(lst->content);
		node = ft_lstnew(tmp);
		if (!node)
		{
			free(tmp);
			ft_lstclear(&new_lst);
			return (0);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}
