/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:54:48 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/11 01:09:52 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ctoi(char *content)
{
	size_t		i;
	int			sign;
	long long	number;

	sign = 1;
	number = 0;
	i = 0;
	if (content[i] == '-' || content[i] == '+')
	{
		if (content[i] == '-')
			sign *= -1;
		i++;
	}
	while (content[i] >= '0' && content[i] <= '9')
	{
		number *= 10;
		number += sign * (content[i] - '0');
		if (number > 2147483647 || number < -2147483648)
			exit_error();
		i++;
	}
	if (i < ft_strlen(content))
		exit_error();
	return (number);
}

static int	stack_check_dup(t_list *stack, int content_num)
{
	while (stack)
	{
		if (*(int *)(stack->content) == content_num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	stack_add(t_list **stack, char **content)
{
	t_list	*new_node;
	int		*content_num;

	while (*content)
	{
		content_num = (int *)malloc(sizeof(int));
		if (!content_num)
			exit_error();
		*content_num = ctoi(*content);
		if (stack_check_dup(*stack, *content_num))
			exit_error();
		new_node = ft_lstnew(content_num);
		if (!content || !new_node)
			exit_error();
		ft_lstadd_back(stack, new_node);
		free(*content);
		content++;
	}
}

t_list	*make_stack(int argc, char **argv)
{
	t_list	*new_stack;
	char	**content;
	int		i;

	new_stack = 0;
	i = 1;
	while (i < argc)
	{
		content = ft_split(argv[i], ' ');
		if (!content)
			exit_error();
		stack_add(&new_stack, content);
		i++;
		free(content);
	}
	return (new_stack);
}

void	stack_to_order(t_list **stack)
{
	t_list	*now;
	int		*sorted_arr;

	sorted_arr = make_arr(*stack);
	bubble_sort(sorted_arr, stacklen(*stack));
	now = *stack;
	while (now)
	{
		*(int *)(now->content)
			= find_order(sorted_arr, *(int *)(now->content), stacklen(*stack));
		now = now->next;
	}
	free(sorted_arr);
}
