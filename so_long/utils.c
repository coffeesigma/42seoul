/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 02:30:06 by jeongbel          #+#    #+#             */
/*   Updated: 2024/06/13 00:56:37 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(void)
{
	if (errno)
		perror("Error\n");
	else
		write(2, "Error\n", 6);
	exit(1);
}

int	key_exit(void)
{
	exit(0);
	return (0);
}

char	*ft_strjoin_withfree(char *s1, char *s2)
{
	char	*join;
	size_t	i;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		exit_error();
	i = 0;
	while (i < ft_strlen(s1))
	{
		join[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		join[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	join[i] = '\0';
	free(s1);
	free(s2);
	return (join);
}

int	dfs(t_info *info, char *map, size_t pos, char find)
{
	int	count;

	count = 0;
	if (map[pos] == '1')
		return (0);
	if (map[pos] == find)
	{
		map[pos] = '1';
		return (1);
	}
	if (map[pos] == '0' || map[pos] == 'P')
	{
		map[pos] = '1';
		count += dfs(info, map, pos - 1, find);
		count += dfs(info, map, pos - info->width, find);
		count += dfs(info, map, pos + 1, find);
		count += dfs(info, map, pos + info->width, find);
		return (count);
	}
	return (0);
}
