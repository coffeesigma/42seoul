/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 00:29:29 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/10 02:21:13 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_op(t_list **op_set)
{
	t_list	*now_op;
	t_list	*comb_op;

	if (stacklen(*op_set) < 2)
		return ;
	now_op = *op_set;
	while (now_op->next)
	{
		comb_op = now_op->next;
		if ((!ft_strcmp(now_op->content, "sa") && !ft_strcmp(comb_op->content, "sb")) || (!ft_strcmp(now_op->content, "sb") && !ft_strcmp(comb_op->content, "sa")))
			now_op->content = "ss";
		else if ((!ft_strcmp(now_op->content, "ra") && !ft_strcmp(comb_op->content, "rb")) || (!ft_strcmp(now_op->content, "rb") && !ft_strcmp(comb_op->content, "ra")))
			now_op->content = "rr";
		else if ((!ft_strcmp(now_op->content, "rra") && !ft_strcmp(comb_op->content, "rrb")) || (!ft_strcmp(now_op->content, "rrb") && !ft_strcmp(comb_op->content, "rra")))
			now_op->content = "rrr";
		else
		{
			now_op = now_op->next;
			continue;
		}
		now_op->next = comb_op->next;
		ft_lstdelone(comb_op, free);
		now_op = now_op->next;
	}
}

void	optimize_rotate(t_list **stack_a, t_list **stack_b, t_list **op_set)
{
	size_t	i;
	t_list	*now;

	i = 0;
	now = *stack_a;
	if (stacklen(*stack_a) < 2)
		return ;
	while (now->next)
	{
		i++;
		if (*(int *)now->content > *(int *)now->next->content)
			break ;
		now = now->next;
	}
	if (i > stacklen(*stack_a) - i)
		while (!is_sorted(*stack_a))
			operate(stack_a, stack_b, op_set, "rra");
	else
		while (!is_sorted(*stack_a))
			operate(stack_a, stack_b, op_set, "ra");
}
