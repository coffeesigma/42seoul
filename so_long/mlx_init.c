/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:36:28 by jeongbel          #+#    #+#             */
/*   Updated: 2024/06/11 15:41:31 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_make(t_info *info, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit_error();
}