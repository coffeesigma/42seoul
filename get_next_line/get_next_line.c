/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:50:00 by jeongbel          #+#    #+#             */
/*   Updated: 2024/01/29 23:02:03 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	check_enter(const char *line)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE];
	static char		*line;
	char			*new_line[2];
	ssize_t			read_size;
	size_t			enter_pos;

	if (fd < 0)
		return (0);
	read_size = 1;
	while (read_size > 0 || ft_strlen(line) != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0) 
		{
			free(line);
			line = 0;
			return (0);
		}
		new_line[1] = ft_strjoin(line, buffer, read_size);
		enter_pos = check_enter(new_line[1]);
		free(line);
		line = 0;
		if (enter_pos < ft_strlen(new_line[1]))
		{
			new_line[0] = ft_substr(new_line[1], 0, enter_pos);
			if (new_line[0])
				line = ft_substr(new_line[1], enter_pos + 1, ft_strlen(new_line[1]) - enter_pos - 1);
			free(new_line[1]);
			new_line[1] = 0;
			return (new_line[0]);
		}
		else 
		{
			if(read_size == 0) 
			{
				free(line);
				line = 0;
				return (new_line[1]);
			}
			line = new_line[1];
		}
	}
	return (0);
}
