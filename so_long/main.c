/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 02:20:42 by jeongbel          #+#    #+#             */
/*   Updated: 2024/06/12 02:52:21 by jeongbel         ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_mlx	*mlx;

	info = (t_info *)malloc(sizeof(t_info));
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!info || !mlx || argc != 2)
		exit_error();
	filename_check(argv[1]);
	map_init(info, argv[1]);
	mlx_make(info, mlx);
	win_make(info, mlx);
	printf("%s\n", info->map);
	printf("%zu %zu\n", info->width, info->height);
	printf("%d\n", info->collect_num);
}
