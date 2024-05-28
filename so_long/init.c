/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:45:00 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/29 04:16:43 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_info *info, char *filename)
{
	int		fd;
	char	*map;
	char	*line;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		exit_error();
	map = get_next_line(fd);
	if (ft_strlen(line) < 3)
		exit_error();
	info->width = ft_strlen(line) - 1;
	info->height = 1;
	info->present = 0;
}
