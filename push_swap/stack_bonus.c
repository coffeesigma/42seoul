/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:48:27 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/13 23:42:27 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	stacklen(t_list *stack)
{
	size_t	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	stack_swap(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;
	t_list	*now;

	if (stacklen(*stack) < 2)
		return ;
	first_node = *stack;
	second_node = first_node->next;
	now = second_node->next;
	second_node->next = first_node;
	first_node->next = now;
	*stack = second_node;
}

void	stack_push(t_list **stack_out, t_list **stack_in)
{
	t_list	*new_stack_out;

	if (stacklen(*stack_out) < 1)
		return ;
	new_stack_out = (*stack_out)->next;
	(*stack_out)->next = 0;
	ft_lstadd_front(stack_in, *stack_out);
	*stack_out = new_stack_out;
}

void	stack_rotate(t_list **stack)
{
	t_list	*first_node;

	first_node = *stack;
	*stack = first_node->next;
	first_node->next = 0;
	ft_lstadd_back(stack, first_node);
}

void	stack_rotate_reverse(t_list **stack)
{
	t_list	*last_node;
	t_list	*last_second_node;

	if (stacklen(*stack) < 2)
		return ;
	last_second_node = *stack;
	while (last_second_node->next->next)
		last_second_node = last_second_node->next;
	last_node = last_second_node->next;
	last_second_node->next = 0;
	last_node->next = *stack;
	*stack = last_node;
}
