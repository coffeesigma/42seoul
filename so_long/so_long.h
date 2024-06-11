/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:37:24 by jeongbel          #+#    #+#             */
/*   Updated: 2024/06/11 15:40:53 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_info
{
	char	*map;
	size_t	width;
	size_t	height;
	size_t	start_x;
	size_t	start_y;
	size_t	exit_x;
	size_t	exit_y;
	int		collect_num;
}	t_info;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*tile;
	void	*wall;
	void	*character;
	void	*collect;
	void	*exit;
}	t_mlx;

void	exit_error(void);
char	*ft_strjoin_withfree(char *s1, char *s2);
char	*gnl_rm_enter(int fd);
void	map_init(t_info *info, char *filename);
void	map_check(t_info *info);

#endif