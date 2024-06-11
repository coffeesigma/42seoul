/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:45:00 by jeongbel          #+#    #+#             */
/*   Updated: 2024/06/12 03:03:44 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*gnl_rm_enter(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	if (ft_strlen(line) < 1)
		return (line);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (line);
}

void	map_init(t_info *info, char *filename)
{
	int		fd;
	char	*map;
	char	*line;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		exit_error();
	map = gnl_rm_enter(fd);
	if (ft_strlen(map) < 3)
		exit_error();
	info->width = ft_strlen(map);
	while (1)
	{
		line = gnl_rm_enter(fd);
		if (!line)
			break ;
		map = ft_strjoin_withfree(map, line);
		if (!map || ft_strlen(line) != info->width)
			exit_error();
	}
	info->height = ft_strlen(map) / info->width;
	info->map = map;
	map_check(info);
	close(fd);
}
