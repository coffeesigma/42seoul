/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:00:39 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/12 21:56:31 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	s1val;
	unsigned char	s2val;

	i = 0;
	while (s1[i] || s2[i])
	{
		s1val = s1[i];
		s2val = s2[i];
		if (s1val != s2val)
			return ((int)(s1val - s2val));
		i++;
	}
	return (0);
}
