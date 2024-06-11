/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:59:17 by jeongbel          #+#    #+#             */
/*   Updated: 2024/06/11 14:45:16 by jeongbel         ###   ########.fr       */
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
	int		start;
	int		exit;

	info->collect_num = 0;
	start = 0;
	exit = 0;
	i = 0;
	while (i < ft_strlen(info->map))
	{
		if (info->map[i] == 'P')
			start++;
		else if (info->map[i] == 'E')
			exit++;
		else if (info->map[i] == 'C')
			info->collect_num++;
		else if (info->map[i] != '0' && info->map[i] != '1')
			exit_error();
		i++;
	}
	if  (start != 1 || exit != 1 || info->collect_num == 0)
		exit_error();
}

void	map_check(t_info *info)
{
	outline_check(info);
	object_check(info);
}
