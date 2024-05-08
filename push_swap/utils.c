/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:50:48 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/08 17:38:58 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

char	*make_arr(t_list *stack)
{
	int		*arr;
	size_t	len;
	size_t	i;

	len = stacklen(stack);
	arr = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		arr[i] = *(int *)(stack->content);
		stack = stack->next;
		i++;
	}
	return (arr);
}

void	bubble_sort(int *arr)
{
	size_t	i;
	size_t	j;
	size_t	len;
	int		tmp;

	len = ft_strlen(arr);
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
		i++;
	}
}

int	is_sorted(t_list *stack)
{
	while (stack)
	{
		if (*(int *)(stack->content) > *(int *)(stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}
