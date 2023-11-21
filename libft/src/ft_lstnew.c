/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 13:59:31 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Library :
	#include "libft.h"
Description :
	Allocates (with malloc(3)) and returns a "fresh" link. The variable content
	of the new link is initialized by copy of the parameter of the function.
	The variable next is initialized to NULL.
Declaration :
	t_list *ft_lstnew(void *content)
Parameters :
	content - the content to put in the new link.
Return Value :
	The new link.
	If the allocation fails, the function returns NULL.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc((sizeof(t_list) * 1));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
