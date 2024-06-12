/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:36:28 by jeongbel          #+#    #+#             */
/*   Updated: 2024/06/13 03:36:20 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_make(t_info *i)
{
	int	w;
	int	h;

	i->mlx = mlx_init();
	if (!i->mlx)
		exit_error();
	i->win = mlx_new_window(i->mlx, 64 * i->width,
			64 * i->height, "./so_long");
	if (!i->win)
		exit_error();
	i->wall = mlx_xpm_file_to_image(i->mlx, "./textures/wall.xpm", &w, &h);
	i->tile = mlx_xpm_file_to_image(i->mlx, "./textures/tile.xpm", &w, &h);
	i->hero = mlx_xpm_file_to_image(i->mlx, "./textures/link.xpm", &w, &h);
	i->collect = mlx_xpm_file_to_image(i->mlx, "./textures/rupy.xpm", &w, &h);
	i->exit = mlx_xpm_file_to_image(i->mlx, "./textures/hiral.xpm", &w, &h);
	if (!i->wall || !i->tile || !i->hero || !i->collect || !i->exit)
		exit_error();
}

void	win_make(t_info *info)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	while (i < ft_strlen(info->map))
	{
		x = i % info->width;
		y = i / info->width;
		if (info->map[i] == '1')
			mlx_put_image_to_window(info->mlx, info->win, info->wall,
				x * 64, y * 64);
		else if (info->map[i] == '0' || info->map[i] == 'E')
			mlx_put_image_to_window(info->mlx, info->win, info->tile,
				x * 64, y * 64);
		else if (info->map[i] == 'P')
			mlx_put_image_to_window(info->mlx, info->win, info->hero,
				x * 64, y * 64);
		else
			mlx_put_image_to_window(info->mlx, info->win, info->collect,
				x * 64, y * 64);
		i++;
	}
}

void	win_make_all_collect(t_info *info)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = -1;
	while (++i < ft_strlen(info->map))
	{
		x = i % info->width;
		y = i / info->width;
		if (info->map[i] == '1')
			mlx_put_image_to_window(info->mlx, info->win, info->wall,
				x * 64, y * 64);
		else if (info->map[i] == '0')
			mlx_put_image_to_window(info->mlx, info->win, info->tile,
				x * 64, y * 64);
		else if (info->map[i] == 'E')
			mlx_put_image_to_window(info->mlx, info->win, info->exit,
				x * 64, y * 64);
		else if (info->map[i] == 'P')
			mlx_put_image_to_window(info->mlx, info->win, info->hero,
				x * 64, y * 64);
		else
			mlx_put_image_to_window(info->mlx, info->win, info->collect,
				x * 64, y * 64);
	}
}

int	key_press(int keycode, t_info *info)
{
	if (keycode == KEY_A)
		move(info, info->start_x + info->start_y * info->width,
			info->start_x + info->start_y * info->width - 1);
	if (keycode == KEY_S)
		move(info, info->start_x + info->start_y * info->width,
			info->start_x + (info->start_y + 1) * info->width);
	if (keycode == KEY_D)
		move(info, info->start_x + info->start_y * info->width,
			info->start_x + info->start_y * info->width + 1);
	if (keycode == KEY_W)
		move(info, info->start_x + info->start_y * info->width,
			info->start_x + (info->start_y - 1) * info->width);
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
