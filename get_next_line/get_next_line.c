/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:50:00 by jeongbel          #+#    #+#             */
/*   Updated: 2023/11/09 21:10:18 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	check_enter(const char buffer[BUFFER_SIZE], ssize_t size)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE && i < (size_t)size)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char		remain[BUFFER_SIZE];
	static ssize_t	remain_size;
	char			buffer[BUFFER_SIZE];
	char			*line;
	ssize_t			read_size;

	if (fd < 0)
		return 0;
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (check_enter(buffer, read_size) != read_size)
		{
			
		}
	}
	

}
