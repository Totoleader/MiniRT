/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:30:09 by gle-roux          #+#    #+#             */
/*   Updated: 2023/06/09 15:48:58 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description :
	The iswhitespace() function tests for any white space character.
Declaration :
	int	ft_iswhitespace(int c)
Parameters :
	c - The character to test.
Return value :
	The isprint() function returns zero if the character tests false and returns 
	non-zero if the character tests true.
*/
int	ft_iswhitespace(int c)
{
	if (('\t' <= c && c <= '\r') || c == 32)
		return (1);
	return (0);
}
