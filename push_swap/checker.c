/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:38:32 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/13 23:42:52 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*op_set;
	char	*op;

	op_set = 0;
	stack_a = make_stack(argc, argv);
	stack_b = 0;
	if (!stacklen(stack_a))
		exit(0);
	while (1)
	{
		op = get_next_line(1);
		if (!op)
			break ;
		if (op[ft_strlen(op) - 1] == '\n')
			op[ft_strlen(op) - 1] = '\0';
		operate(&stack_a, &stack_b, &op_set, op);
		free(op);
	}
	if (is_sorted(stack_a) && stacklen(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(0);
}
