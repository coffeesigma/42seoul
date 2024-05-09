/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:09:10 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/10 02:58:49 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack_2_b(t_list **stack_a, t_list **stack_b, t_list **op_set)
{
	t_list	*last_op;

	write(1, "print2\n", 7);
	print_op(*op_set);
	write(1, "end\n", 4);
	last_op = *op_set;
	while (last_op->next)
		last_op = last_op->next;
	if (!ft_strcmp(last_op->content, "sa"))
		operate(stack_a, stack_b, op_set, "sb");
	else if (!ft_strcmp(last_op->content, "rra"))
		operate(stack_a, stack_b, op_set, "rrb");
	else
		operate(stack_a, stack_b, op_set, "rb");
}

static void	sort_stack_3(t_list **stack_a, t_list **stack_b, t_list **op_set)
{
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
	{
		if (*(int *)(*stack_a)->next->next->content > *(int *)(*stack_a)->next->content)
		{
			if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->next->content)
				operate(stack_a, stack_b, op_set, "ra");
			else
				operate(stack_a, stack_b, op_set, "sa");
		}
		else
		{
			operate(stack_a, stack_b, op_set, "sa");
			operate(stack_a, stack_b, op_set, "rra");
		}
	}
	else
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->next->content)
			operate(stack_a, stack_b, op_set, "rra");
		else
		{
			operate(stack_a, stack_b, op_set, "ra");
			operate(stack_a, stack_b, op_set, "sa");
			operate(stack_a, stack_b, op_set, "rra");
		}
	}
}

static void	sort_stack_4(t_list **stack_a, t_list **stack_b, t_list **op_set)
{
	operate(stack_a, stack_b, op_set, "pb");
	if (!is_sorted(*stack_a))
		sort_stack_3(stack_a, stack_b, op_set);
	while (*(int *)(*stack_a)->content < *(int *)(*stack_b)->content)
		operate(stack_a, stack_b, op_set, "ra");
	operate(stack_a, stack_b, op_set, "pa");
	optimize_rotate(stack_a, stack_b, op_set);
}

static void	sort_stack_5(t_list **stack_a, t_list **stack_b, t_list **op_set)
{
	operate(stack_a, stack_b, op_set, "pb");
	operate(stack_a, stack_b, op_set, "pb");
	if (!is_sorted(*stack_a))
		sort_stack_3(stack_a, stack_b, op_set);
	if (!is_sorted(*stack_b))
		sort_stack_2_b(stack_a, stack_b, op_set);
	while (*(int *)(*stack_a)->content < *(int *)(*stack_b)->content)
		operate(stack_a, stack_b, op_set, "ra");
	operate(stack_a, stack_b, op_set, "pa");
	while (*(int *)(*stack_a)->content < *(int *)(*stack_b)->content)
		operate(stack_a, stack_b, op_set, "ra");
	operate(stack_a, stack_b, op_set, "pa");
	optimize_rotate(stack_a, stack_b, op_set);
}

void	sort_lower(t_list **stack_a, t_list **stack_b, t_list **op_set)
{
	size_t	len;

	len = stacklen(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (len == 2)
		operate(stack_a, stack_b, op_set, "ra");
	else if (len == 3)
		sort_stack_3(stack_a, stack_b, op_set);
	else if (len == 4)
		sort_stack_4(stack_a, stack_b, op_set);
	else if (len == 5)
		sort_stack_5(stack_a, stack_b, op_set);
	else
		return ;
}
