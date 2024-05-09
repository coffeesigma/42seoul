/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:07:25 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/10 00:37:52 by jeongbel         ###   ########.fr       */
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

static void	operate_solo(t_list **stack_a, t_list **stack_b, char *op)
{
	if (!ft_strcmp(op, "sa"))
		stack_swap(stack_a);
	else if (!ft_strcmp(op, "sb"))
		stack_swap(stack_b);
	else if (!ft_strcmp(op, "pa"))
		stack_push(stack_b, stack_a);
	else if (!ft_strcmp(op, "pb"))
		stack_push(stack_a, stack_b);
	else if (!ft_strcmp(op, "ra"))
		stack_rotate(stack_a);
	else if (!ft_strcmp(op, "rb"))
		stack_rotate(stack_b);
	else if (!ft_strcmp(op, "rra"))
		stack_rotate_reverse(stack_a);
	else if (!ft_strcmp(op, "rrb"))
		stack_rotate_reverse(stack_a);
	else
		exit_error();
}

void	operate(t_list **stack_a, t_list **stack_b, t_list **op_set, char *op)
{
	t_list	*new_op;

	new_op = ft_lstnew(op);
	if (!new_op)
		exit_error();
	ft_lstadd_back(op_set, new_op);
	if (!ft_strcmp(op, "ss"))
	{
		stack_swap(stack_a);
		stack_swap(stack_b);
	}
	else if (!ft_strcmp(op, "rr"))
	{
		stack_rotate(stack_a);
		stack_rotate(stack_b);
	}
	else if (!ft_strcmp(op, "rrr"))
	{
		stack_rotate_reverse(stack_a);
		stack_rotate_reverse(stack_b);
	}
	else
		operate_solo(stack_a, stack_b, op);
}
