/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 02:30:06 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/29 03:18:19 by jeongbel         ###   ########.fr       */
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

char	*ft_strjoin_withfree(char *s1, char *s2)
{
	char	*join;
	size_t	i;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (0);
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
