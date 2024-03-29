/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:50:00 by jeongbel          #+#    #+#             */
/*   Updated: 2024/01/30 07:17:56 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	check_enter(const char *line)
{
	size_t	i;
	size_t	line_size;

	i = 0;
	line_size = ft_strlen(line);
	while (i < line_size)
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*make_new_line(char *buffer, char **line, size_t read_size)
{
	char	*comb_line;
	char	*new_line;
	size_t	enter;

	comb_line = ft_strjoin(*line, buffer, read_size);
	enter = check_enter(comb_line);
	free(*line);
	*line = 0;
	if (enter < ft_strlen(comb_line) || read_size == 0)
	{
		new_line = ft_substr(comb_line, 0, enter);
		if (new_line)
			*line = ft_substr(comb_line, enter + 1,
					ft_strlen(comb_line) - enter - 1);
		free(comb_line);
		comb_line = 0;
		return (new_line);
	}
	*line = comb_line;
	return (0);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*line;
	ssize_t			read_size;
	char			*new_line;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
	{
		free(line);
		line = 0;
		return (0);
	}
	read_size = 1;
	while (read_size > 0 || line)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
			break ;
		new_line = make_new_line(buffer, &line, read_size);
		if (new_line)
		{
			free(buffer);
			buffer = 0;
			return (new_line);
		}
	}
	free(line);
	line = 0;
	free(buffer);
	buffer = 0;
	return (0);
}
