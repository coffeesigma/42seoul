/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:50:48 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/13 23:41:53 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	*make_arr(t_list *stack)
{
	int		*arr;
	size_t	len;
	size_t	i;

	len = stacklen(stack);
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		exit_error();
	i = 0;
	while (i < len)
	{
		arr[i] = *(int *)(stack->content);
		stack = stack->next;
		i++;
	}
	return (arr);
}

void	bubble_sort(int *arr, size_t len)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = len - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i--;
	}
}

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (*(int *)(stack->content) > *(int *)(stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	print_op(t_list *op_set)
{
	while (op_set)
	{
		write(1, op_set->content, ft_strlen(op_set->content));
		write(1, "\n", 1);
		op_set = op_set->next;
	}
}
