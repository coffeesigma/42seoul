/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:52:05 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/08 17:46:50 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*op_set;
	int		sorted_arr;

	stack_a = make_stack(argc, argv);
	stack_b = 0;
	sorted_arr = make_arr(stack_a);
	bubble_sort(sorted_arr);
	
}
