/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:52:05 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/09 17:03:00 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	check_leak(void)
{
	system("leaks push_swap");
}

void	print_stack(t_list *stack)
{
	while (stack)
    {
		int *k = stack->content;
		printf("%d ", *k);
		stack = stack->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*op_set;
	//int		*sorted_arr;

    op_set = 0;
	stack_a = make_stack(argc, argv);
	stack_b = 0;
    print_stack(stack_a);
    print_stack(stack_b);
    sort_lower(&stack_a, &stack_b, &op_set);
    print_stack(stack_a);
    print_stack(stack_b);
	//sorted_arr = make_arr(stack_a);
	//bubble_sort(sorted_arr);
    print_op(op_set);
    atexit(check_leak);
    return (0);
}
