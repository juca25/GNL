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

	len = 0;
	while (list != NULL)
	{
		i = 0;
		while (!list->str_buf[i])
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

	j = 0;
	while (list != NULL)
	{
		i = 0;
		while (!list->str_buf[i])
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

t_list	*LF_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

//free todo el heap
void	ft_dealloc(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if(*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->str_buf[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}

int	LF_newline(t_list *list)
{
	int	i;

	if(list == NULL)
		return (0);
	while(list != 0)
	{
		i = 0;
		while (list->str_buf[i] && i < BUFFER_SIZE)
		{
				if(list->str_buf[i] == '\n')
					return (i);
				i++;
		}
		list = list->next;
	}
	return (0);
}