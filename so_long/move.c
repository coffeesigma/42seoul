/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:29:47 by jeongbel          #+#    #+#             */
/*   Updated: 2024/06/12 19:31:58 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_info *info, size_t now, size_t next)
{
	if (info->map[next] == 'C')
		info->collect_num -= 1;
	if (info->map[next] == 'E' && info->collect_num == 0)
		exit(0);
	else if (info->map[next] != '1')
	{
		info->map[now] = '0';
		info->map[next] = 'P';
		info->count++;
		info->start_x = next % info->width;
		info->start_y = next / info->width;
		// print count
		printf("%d\n", info->count);
		if (info->collect_num == 0)
			win_make_all_collect(info);
		else
			win_make(info);
	}
}
