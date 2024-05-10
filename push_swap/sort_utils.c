/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 07:48:23 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/10 14:48:53 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_order(int *sorted_arr, int find, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (sorted_arr[i] == find)
			break ;
		i++;
	}
	return (i);
}

int	order_distance(int a, int b, int *sorted_arr, size_t len)
{
	size_t a_order;
	size_t b_order;

	a_order = find_order(sorted_arr, a, len);
	b_order = find_order(sorted_arr, b, len);
	return (a - b);
}

int	min_dist(int arr[3])
{
	int	min;
	int	i;

	min = 2147483647;
	i = 0;
	while (i < 3)
	{
		if (min > arr[i] && arr[i] > 0)
			min = arr[i];
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (min == arr[i])
			break;
		i++;
	}
	return (i);
}

int	min_dist_sorted(int arr[3], int max_a)
{
	int	min;
	int	i;

	min = 2147483647;
	i = 0;
	while (i < 3)
	{
		if (min > ft_abs(arr[i]) && arr[i] > 0)
			min = ft_abs(arr[i]);
		if (min > ft_abs(arr[i] + max_a) && arr[i] + max_a < 0)
			min = ft_abs(arr[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (min == ft_abs(arr[i]))
			break;
		i++;
	}
	return (i);
}

int	min_dist_r(int arr[3])
{
	int	min;
	int	i;

	min = 2147483647;
	i = 0;
	while (i < 3)
	{
		if (min > ft_abs(arr[i]))
			min = ft_abs(arr[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (min == ft_abs(arr[i]))
			break;
		i++;
	}
	return (i);
}

void	select_pa(t_list **stack_a, t_list **stack_b, t_list **op_set, int n)
{
	if (n == 1)
	{
		if (ft_strcmp(ft_lstlast(*op_set)->content, "sa"))
			operate(stack_a, stack_b, op_set, "sb");
		else
			operate(stack_a, stack_b, op_set, "rb");
	}
	if (n == 2)
		operate(stack_a, stack_b, op_set, "rrb");
	if (n == 0 || n == 1 || n == 2)
		operate(stack_a, stack_b, op_set, "pa");
}

void	select_ra(t_list **stack_a, t_list **stack_b, t_list **op_set, int n)
{
	int	i;
	
	i = 0;
	while (i > n)
	{
		operate(stack_a, stack_b, op_set, "ra");
		i--;
	}
	i = 0;
	while (i < n - 1)
	{
		operate(stack_a, stack_b, op_set, "rra");
		i++;
	}
	operate(stack_a, stack_b, op_set, "pa");
}
