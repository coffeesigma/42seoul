/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 04:22:16 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/10 08:14:12 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_num(t_list *stack)
{
	int	max;

	max = -2147483648;
	while (stack)
	{
		if (max < *(int *)stack->content)
			max = *(int *)stack->content;
		stack = stack->next;
	}
	return (max);
}

int	min_num(t_list *stack)
{
	int	min;

	min = 2147483647;
	while (stack)
	{
		if (min > *(int *)stack->content)
			min = *(int *)stack->content;
		stack = stack->next;
	}
	return (min);
}

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

int	ft_abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}
