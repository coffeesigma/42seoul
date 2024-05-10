/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:52:05 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/10 14:26:31 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_leak(void)
{
	system("leaks push_swap");
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
	if (stacklen(stack_a) < 6)
		sort_lower(&stack_a, &stack_b, &op_set);
	else
		sort_stack(&stack_a, &stack_b, &op_set);
	optimize_op(&op_set);
	print_op(op_set);
	//atexit(check_leak);
	exit(0);
	return (0);
}
