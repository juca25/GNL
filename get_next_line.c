/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:23:32 by juan-ser          #+#    #+#             */
/*   Updated: 2024/11/11 14:29:17 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_buffer(int fd, char *buf)
{
	char	*temp;
	int		char_read;
	
	if (!buf)
		buf = ft_calloc(sizeof(char), 1);
	temp = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buf || !temp)
		return (NULL);
	char_read = 1;
	while(!ft_strchr(temp, '\n') && char_read != 0)
	{
		char_read = read(fd, temp, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(temp);
			free(buf);
			return (NULL);
		}
		temp[char_read] = '\0';
		buf = ft_strjoin(buf, temp);
	}
	free(temp);
	return (buf);
}

char *ft_get_line(char *buf)
{
	char	*line;
	int		len;
	
	len = 0;
	if (!buf[len])
		return (NULL);
	while (buf[len] != '\n' && buf[len] != '\0')
		len++;
	line = ft_calloc(sizeof(char), len + 2);
	if (!line)
		return (NULL);
	len = 0;
	ft_strcopy(buf, line);
	return (line);
}

char *ft_clean_string(char *buf)
{
	char *temp;
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	temp = ft_calloc(sizeof(char), ft_strlen(buf) - i + 1);
	if (!temp)
		return (NULL);
	i++;
	while (buf[i] != '\0')
		temp[j++] = buf[i++];
	free(buf);
	return (temp);
}

char *get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_get_buffer(fd, buf);
	if(buf == NULL)
		return (NULL);
	line = ft_get_line(buf);
	buf = ft_clean_string(buf);
	return (line);
}

int main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}