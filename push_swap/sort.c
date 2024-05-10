/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 05:33:27 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/10 15:00:54 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// #include <stdio.h>
// static void	print_stack(t_list *stack)
// {
// 	while (stack)
// 	{
// 		int	*k = stack->content;
// 		printf("%d ", *k);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

static int	*set_pivot(int *sorted_arr, size_t len)
{
	int		*pivot;

	pivot = (int *)malloc(sizeof(int) * 2);
	if (!pivot)
		exit_error();
	pivot[0] = sorted_arr[len / 3];
	pivot[1] = sorted_arr[(len / 3) * 2];
	return (pivot);
}

static void	push_b(t_list **stack_a, t_list **stack_b, t_list **op_set, int *pivot)
{
	while (min_num(*stack_a) <= pivot[1])
	{
		if (*(int *)(*stack_a)->content <= pivot[1])
		{
			operate(stack_a, stack_b, op_set, "pb");
			if (*(int *)(*stack_b)->content > pivot[0])
				operate(stack_a, stack_b, op_set, "rb");
		}
		else
			operate(stack_a, stack_b, op_set, "ra");
	}
	while (stacklen(*stack_a) > 3)
		operate(stack_a, stack_b, op_set, "pb");
	sort_lower(stack_a, stack_b, op_set);
}

static void	push_a(t_list **stack_a, t_list **stack_b, t_list **op_set, int *arr, size_t len)
{
	int	dist[3];
	int	min_node;
	int	min_node_sorted;

	while (stacklen(*stack_b) > 2)
	{
		// print_stack(*stack_a);
		// print_stack(*stack_b);
		dist[0] = order_distance(*(int *)(*stack_a)->content, *(int *)(*stack_b)->content, arr, len);
		dist[1] = order_distance(*(int *)(*stack_a)->content, *(int *)(*stack_b)->next->content, arr, len);
		dist[2] = order_distance(*(int *)(*stack_a)->content, *(int *)ft_lstlast(*stack_b)->content, arr, len);
		min_node = min_dist(dist);
		min_node_sorted = min_dist_sorted(dist, max_num(*stack_a) - min_num(*stack_a));
		if (*(int *)(*stack_a)->content != min_num(*stack_a) && min_node < 3
			&& dist[min_node] < order_distance(*(int *)(*stack_a)->content, *(int *)ft_lstlast(*stack_a)->content, arr, len))
			select_pa(stack_a, stack_b, op_set, min_node);
		else if (*(int *)(*stack_a)->content == min_num(*stack_a) && min_node_sorted < 3)
			select_pa(stack_a, stack_b, op_set, min_node_sorted);
		else
		{
			if (*(int *)(*stack_b)->content > max_num(*stack_a))
				operate(stack_a, stack_b, op_set, "rb");
			if (dist[min_dist_r(dist)] < 0)
				operate(stack_a, stack_b, op_set, "ra");
			else
				operate(stack_a, stack_b, op_set, "rra");
		}
		// printf("%s\n", ft_lstlast(*op_set)->content);
	}
	dist[0] = order_distance(*(int *)(*stack_a)->content, *(int *)(*stack_b)->content, arr, len);
	dist[1] = order_distance(*(int *)(*stack_a)->content, *(int *)(*stack_b)->next->content, arr, len);
	if (ft_abs(dist[0]) < ft_abs(dist[1]))
		select_ra(stack_a, stack_b, op_set, dist[0]);
	else
	{
		operate(stack_a, stack_b, op_set, "rb");
		select_ra(stack_a, stack_b, op_set, dist[1]);
	}
	select_ra(stack_a, stack_b, op_set, order_distance(*(int *)(*stack_a)->content, *(int *)(*stack_b)->content, arr, len));
	// print_stack(*stack_a);
	// print_stack(*stack_b);
	optimize_rotate(stack_a, stack_b, op_set);
}

void	sort_stack(t_list **stack_a, t_list **stack_b, t_list **op_set)
{
	int		*pivot;
	int		*sorted_arr;
	size_t	len;

	if (is_sorted(*stack_a))
		return ;
	len = stacklen(*stack_a);
	sorted_arr = make_arr(*stack_a);
	bubble_sort(sorted_arr, len);
	pivot = set_pivot(sorted_arr, len);
	push_b(stack_a, stack_b, op_set, pivot);
	push_a(stack_a, stack_b, op_set, sorted_arr, len);
}
