/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:53:18 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/08 15:51:39 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "libft/get_next_line.h"
#include <stdio.h>

void	check_leak(void)
{
	system("leaks push_swap");
}

void	print_stack(t_list *stack)
{
	while (stack) {
		int *k = stack->content;
		printf("%d ", *k);
		stack = stack->next;
	}
	printf("\n");
}

int main(int argc, char **argv) {
	//char *c = get_next_line(1);
	t_list *stack_a = make_stack(argc, argv);
	t_list *stack_b;

	stack_b = 0;
	print_stack(stack_a);
	print_stack(stack_b);
	operate(&stack_a, &stack_b, "sa");
	operate(&stack_a, &stack_b, "pb");
	operate(&stack_a, &stack_b, "pb");
	operate(&stack_a, &stack_b, "ss");
	print_stack(stack_a);
	print_stack(stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	atexit(check_leak);
	return 0;	
}
