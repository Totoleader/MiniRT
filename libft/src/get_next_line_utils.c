/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:23:28 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/31 14:00:51 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*Memory allocation*/
void	*ft_calloc_gnl(size_t count, size_t size)
{
	size_t	i;
	char	*dest;

	dest = (void *)malloc(size * count);
	if (!dest)
		return (0);
	i = 0;
	while (i < (count * size))
		dest[i++] = 0;
	return (dest);
}

/*
  Check a string to find the new line character ('\n')
  Returns 1 if '\n' is found in the string
*/
int	ft_strchr_new_line(char *save)
{
	size_t	i;

	if (!save)
		return (0);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*Joins buffer and save*/
char	*ft_strnjoin(char *temp, char *buf)
{
	size_t	i;
	size_t	j;
	size_t	len_temp;
	size_t	len_buf;
	char	*save;

	len_temp = 0;
	while (temp && temp[len_temp])
		len_temp++;
	len_buf = 0;
	while (buf && buf[len_buf])
		len_buf++;
	save = ft_calloc(sizeof * save, len_temp + len_buf + 1);
	if (!save)
		return (NULL);
	i = 0;
	while (temp && len_temp--)
	{
		save[i] = temp[i];
		i++;
	}
	j = 0;
	while (buf && len_buf--)
		save[i++] = buf[j++];
	return (save);
}

/*
  Duplicate a string
  (memory allocation + copy)
*/
char	*ft_strdup_gnl(char *save)
{
	int		i;
	int		len;
	char	*temp;

	if (!save)
		return (0);
	len = 0;
	while (save[len])
		len++;
	temp = ft_calloc(sizeof * temp, len + 1);
	if (!temp)
		return (0);
	i = 0;
	while (save[i])
	{
		temp[i] = save[i];
		i++;
	}
	return (temp);
}

/*Free a string if it exists*/
void	*ft_free(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (0);
}
