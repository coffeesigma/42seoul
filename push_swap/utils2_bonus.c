/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 04:22:16 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/13 23:42:00 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}
