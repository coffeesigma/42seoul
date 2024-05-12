/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 05:33:27 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/12 20:51:57 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_op(t_list **stack_a, t_list **stack_b, t_list **op_set,
	int do_rotate[2])
{
	int	ra_num;
	int	rb_num;
	int	i;

	ra_num = ft_abs(do_rotate[0]);
	rb_num = ft_abs(do_rotate[1]);
	i = 0;
	while (i < ra_num || i < rb_num)
	{
		if (do_rotate[0] < 0 && i < ra_num)
			operate(stack_a, stack_b, op_set, "rra");
		if (do_rotate[0] > 0 && i < ra_num)
			operate(stack_a, stack_b, op_set, "ra");
		if (do_rotate[1] < 0 && i < rb_num)
			operate(stack_a, stack_b, op_set, "rrb");
		if (do_rotate[1] > 0 && i < rb_num)
			operate(stack_a, stack_b, op_set, "rb");
		i++;
	}
	operate(stack_a, stack_b, op_set, "pa");
}

static void	decide_op(t_list **stack_a, t_list **stack_b, t_list **op_set,
	int rotate[2])
{
	int	len_a;
	int	len_b;
	int	min;
	int	do_rotate[2];

	len_a = stacklen(*stack_a);
	len_b = stacklen(*stack_b);
	min = op_count(rotate[0], rotate[1], len_a, len_b);
	do_rotate[0] = rotate[0];
	do_rotate[1] = rotate[1];
	if (ft_max(len_a - rotate[0], len_b - rotate[1]) == min)
	{
		do_rotate[0] = rotate[0] - len_a;
		do_rotate[1] = rotate[1] - len_b;
	}
	else if (rotate[0] + len_b - rotate[1] == min)
		do_rotate[1] = rotate[1] - len_b;
	else if (len_a - rotate[0] + rotate[1] == min)
		do_rotate[0] = rotate[0] - len_a;
	do_op(stack_a, stack_b, op_set, do_rotate);
}

static void	push_a(t_list **stack_a, t_list **stack_b, t_list **op_set)
{
	t_list	*now;
	int		min;
	int		b;
	int		rotate[2];

	while (stacklen(*stack_b))
	{
		min = 2147483647;
		now = *stack_b;
		while (now)
		{
			if (min > find_min_op(*stack_a, *stack_b, *(int *)now->content))
			{
				min = find_min_op(*stack_a, *stack_b, *(int *)now->content);
				b = *(int *)now->content;
			}
			now = now->next;
		}
		rotate[0] = find_ra(*stack_a, b);
		rotate[1] = find_rb(*stack_b, b);
		decide_op(stack_a, stack_b, op_set, rotate);
	}
	optimize_rotate(stack_a, stack_b, op_set);
}

static void	push_b(t_list **stack_a, t_list **stack_b, t_list **op_set)
{
	int	pivot1;
	int	pivot2;

	pivot1 = stacklen(*stack_a) / 3;
	pivot2 = pivot1 * 2;
	while (min_num(*stack_a) <= pivot2)
	{
		if (*(int *)(*stack_a)->content <= pivot2)
		{
			operate(stack_a, stack_b, op_set, "pb");
			if (*(int *)(*stack_b)->content > pivot1)
				operate(stack_a, stack_b, op_set, "rb");
		}
		else
			operate(stack_a, stack_b, op_set, "ra");
	}
	while (stacklen(*stack_a) > 3)
		operate(stack_a, stack_b, op_set, "pb");
	sort_lower(stack_a, stack_b, op_set);
}

void	sort_stack(t_list **stack_a, t_list **stack_b, t_list **op_set)
{
	if (is_sorted(*stack_a))
		return ;
	push_b(stack_a, stack_b, op_set);
	push_a(stack_a, stack_b, op_set);
}
