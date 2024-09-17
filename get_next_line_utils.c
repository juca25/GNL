/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:23:29 by juan-ser          #+#    #+#             */
/*   Updated: 2024/09/17 13:10:06 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline_len(t_list *list)
{
	int	i;
	int	len;
	
	if (list == NULL)
		return (NULL);
	len = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->str_buf[i] != NULL)
		{
			if (list->str_buf[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	ft_strcopy(t_list *list, char *str)
{
	int	i;
	int	j;

	if (list == NULL)
		return (NULL);
	j = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->str_buf[i] != NULL)
		{
			if (list->str_buf[i] == '\n')
			{
				str[j + 1] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j + 1] = list->str_buf[i + 1];
		}
		list = list->next;
	}
	str[j] = '\0';
}