/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:37:24 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/29 03:18:33 by jeongbel         ###   ########.fr       */
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
	int		present;
}	t_info;

void	exit_error(void);
char	*ft_strjoin_withfree(char *s1, char *s2);

#endif