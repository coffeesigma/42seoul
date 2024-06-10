/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:59:17 by jeongbel          #+#    #+#             */
/*   Updated: 2024/06/10 20:56:39 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	outline_check(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			if (i == 0 || i == info->height - 1
				|| j == 0 || j == info->width - 1)
			{
				if (info->map[i * info->width + j] != '1')
					exit_error();
			}
			j++;
		}
		i++;
	}
}

static void	object_check(t_info *info)
{
	size_t	i;
	size_t	j;
	char	now;

	info->collect_num = 0;
	i = 1;
	while (i < info->height - 1)
	{
		j = 1;
		while (j < info->width - 1)
		{
			now = info->map[i * info->width + j];
			if (now == 'P')
			{
				info->start_x = i;
				info->start_y = j;
			}
			else if (now == 'C')
				info->collect_num++;
		}
	}

}

void	map_check(t_info *info)
{
	outline_check(info);
}
