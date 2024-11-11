/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:21:17 by juan-ser          #+#    #+#             */
/*   Updated: 2024/11/11 14:09:24 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

char *get_next_line(int fd);
char *ft_get_buffer(int fd, char *buf);
char *ft_get_line(char *buf);
char *ft_clean_string(char *buf);
int ft_strlen(char *str);
void *ft_calloc(size_t size, size_t count);
char	*ft_strjoin(char *s1, char *s2);
char *ft_strchr(char *str, char c);
void ft_strcopy(char *src, char *dest);

#endif