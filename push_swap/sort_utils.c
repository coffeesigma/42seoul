/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 07:48:23 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/12 20:43:36 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_order(int *sorted_arr, int find, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (sorted_arr[i] == find)
			break ;
		i++;
	}
	return (i);
}

int	find_min_op(t_list *stack_a, t_list *stack_b, int b)
{
	int	ro[2];

	ro[0] = find_ra(stack_a, b);
	ro[1] = find_rb(stack_b, b);
	return (op_count(ro[0], ro[1], stacklen(stack_a), stacklen(stack_b)));
}

int	op_count(int rotate_a, int rotate_b, int len_a, int len_b)
{
	int	max;
	int	max2;
	int	min;
	int	min2;

	max = ft_max(rotate_a, rotate_b);
	max2 = ft_max(len_a - rotate_a, len_b - rotate_b);
	min = ft_min(max, max2);
	min2 = ft_min(rotate_a + len_b - rotate_b, len_a - rotate_a + rotate_b);
	min = ft_min(min, min2);
	return (min);
}

int	find_ra(t_list *stack, int b)
{
	int	rotate_a;
	int	max;
	int	min;
	int	first_content;

	max = max_num(stack);
	min = min_num(stack);
	first_content = *(int *)stack->content;
	rotate_a = 0;
	while (stack->next)
	{
		rotate_a++;
		if ((*(int *)stack->content < b && *(int *)stack->next->content > b)
			|| ((max < b || min > b)
				&& *(int *)stack->content > *(int *)stack->next->content))
			break ;
		stack = stack->next;
	}
	if (!stack->next)
		if ((*(int *)stack->content < b && first_content > b)
			|| ((max < b || min > b)
				&& *(int *)stack->content > first_content))
			rotate_a++;
	return (rotate_a);
}

int	find_rb(t_list *stack, int b)
{
	int	rotate_b;

	rotate_b = 0;
	while (stack)
	{
		if (*(int *)stack->content == b)
			break ;
		rotate_b++;
		stack = stack->next;
	}
	return (rotate_b);
}
