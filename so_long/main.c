/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 02:20:42 by jeongbel          #+#    #+#             */
/*   Updated: 2024/06/13 04:35:04 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	filename_check(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
		exit_error();
	if (!(filename[len - 4] == '.' && filename[len - 3] == 'b'
			&& filename[len - 2] == 'e' && filename[len - 1] == 'r'))
		exit_error();
	if (filename[len - 5] == '/')
		exit_error();
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info || argc != 2)
		exit_error();
	filename_check(argv[1]);
	map_init(info, argv[1]);
	mlx_make(info);
	win_make(info);
	mlx_hook(info->win, 2, 0, key_press, info);
	mlx_hook(info->win, KEY_EXIT, 0, key_exit, NULL);
	mlx_loop(info->mlx);
}
