/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 00:29:29 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/12 21:52:58 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	change_op(t_list *node, char *content)
{
	t_list	*del;

	del = node->next;
	node->content = content;
	node->next = del->next;
	free(del);
}

void	optimize_op(t_list **op_set)
{
	t_list	*n;
	t_list	*d;

	if (stacklen(*op_set) < 2)
		return ;
	n = *op_set;
	while (n->next)
	{
		d = n->next;
		if (!(ft_strcmp(n->content, "sa") || ft_strcmp(d->content, "sb"))
			|| !(ft_strcmp(n->content, "sb") || ft_strcmp(d->content, "sa")))
			change_op(n, "ss");
		else if (!(ft_strcmp(n->content, "ra") || ft_strcmp(d->content, "rb"))
			|| !(ft_strcmp(n->content, "rb") || ft_strcmp(d->content, "ra")))
			change_op(n, "rr");
		else if (!(ft_strcmp(n->content, "rra") || ft_strcmp(d->content, "rrb"))
			|| !(ft_strcmp(n->content, "rrb") || ft_strcmp(d->content, "rra")))
			change_op(n, "rrr");
		n = n->next;
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
