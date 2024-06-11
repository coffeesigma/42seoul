/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:36:28 by jeongbel          #+#    #+#             */
/*   Updated: 2024/06/12 03:03:11 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_make(t_info *info, t_mlx *mlx)
{
	int	w;
	int	h;

	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit_error();
	mlx->win = mlx_new_window(mlx->mlx, 64 * info->width,
			64 * info->height, "./so_long");
	if (!mlx->win)
		exit_error();
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx, "./textures/wall.xpm", &w, &h);
	mlx->tile = mlx_xpm_file_to_image(mlx->mlx, "./textures/tile.xpm", &w, &h);
	mlx->hero = mlx_xpm_file_to_image(mlx->mlx, "./textures/link.xpm", &w, &h);
	mlx->collect = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/rupy.xpm", &w, &h);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, "./textures/hiral.xpm", &w, &h);
}

void	win_make(t_info *info, t_mlx *mlx)
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
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall,
				x * 64, y * 64);
		else if (info->map[i] == '0' || info->map[i] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tile,
				x * 64, y * 64);
		else if (info->map[i] == 'P')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->hero,
				x * 64, y * 64);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->collect,
				x * 64, y * 64);
		i++;
	}
}
