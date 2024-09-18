/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:21:17 by juan-ser          #+#    #+#             */
/*   Updated: 2024/09/11 12:52:37 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

//nodo de lista enlazada
typedef struct s_list
{
	char			*str_buf;
	struct	s_list	*next;	
}					t_list;

char	*get_next_line(int fd);
int		newline_len(t_list *list);
void	ft_strcopy(t_list *list, char *str);
void	ft_dealloc(t_list **list, t_list *clean_node, char *buf);
char	*get_line(t_list *list);
void	ft_append(t_list **list, char	*buf);
void	create_list(t_list **list, int fd);
void	clean_list(t_list **list);
char	*get_next_line(int fd);
t_list	*LF_last_node(t_list *list);
int	LF_newline(t_list *list);

#endif