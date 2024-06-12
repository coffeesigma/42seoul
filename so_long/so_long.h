/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:37:24 by jeongbel          #+#    #+#             */
/*   Updated: 2024/06/12 19:24:13 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# include "./libft/libft.h"
# include "./mlx_gl/mlx.h"
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
	int		count;
	void	*mlx;
	void	*win;
	void	*tile;
	void	*wall;
	void	*hero;
	void	*collect;
	void	*exit;
}	t_info;

void	exit_error(void);
char	*ft_strjoin_withfree(char *s1, char *s2);
char	*gnl_rm_enter(int fd);
void	map_init(t_info *info, char *filename);
void	map_check(t_info *info);
void	filename_check(char *filename);
void	mlx_make(t_info *info);
void	win_make(t_info *info);
void	win_make_all_collect(t_info *info);
int		key_press(int keycode, t_info *info);

void	move(t_info *info, size_t now, size_t next);

#endif