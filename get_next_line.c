/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:23:32 by juan-ser          #+#    #+#             */
/*   Updated: 2024/09/17 13:09:58 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;
	
	if (list == NULL)
		return (NULL);
	str_len = newline_len(list);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	ft_strcopy(list, next_str);
	return (next_str);
}
void	ft_append(t_list **list, char	*buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = LF_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		return ;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}
void	create_list(t_list **list, int fd)
{
	int	char_read;
	char	*buf;
	
	while (!LF_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
									//42
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		// append nodo
		ft_append(list, buf);
	}
}

void clean_list(t_list **list)
{
	t_list *last_node;
	t_list *clean_node;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = LF_last_node(*list);

	i = 0;
	j = 0;
	while(last_node->str_buf[i] != '\n' && last_node->str_buf[i] != 0)
		i++;
	while (last_node->str_buf[i] != 0 && last_node->str_buf[i + 1])
		buf[j + 1] = last_node->str_buf[i];
	buf[j] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	ft_dealloc(list, clean_node,buf);
}


char *get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;
	
	//fd solo puede ser positivo 
	//read da -1 si hay algun problema (ultimo control)
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line,0) < 0)
		return (NULL);
	
	//crea nueva lista cuando i coincide con '\n'
	create_list(&list, fd);
	
	if (list == NULL)
		return (NULL);
	//busca la linea en la lista
	next_line = get_line(list);
	clean_list(&list);
	return (next_line);
}


int main()
{
	int fd;
	char	*line;
	int	lines;

	lines = 1;
	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
		printf("%d->%s\n", lines++, line);
}
