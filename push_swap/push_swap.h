/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:52:42 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/10 13:25:30 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

t_list	*make_stack(int argc, char **argv);
void	exit_error(void);
int		*make_arr(t_list *stack);
void	bubble_sort(int *arr, size_t len);
int		is_sorted(t_list *stack);
void	print_op(t_list *op_set);
int		max_num(t_list *stack);
int		min_num(t_list *stack);
int		ft_strcmp(char *s1, char *s2);
int		ft_abs(int a);
size_t	stacklen(t_list *stack);
void	stack_swap(t_list **stack);
void	stack_push(t_list **stack_out, t_list **stack_in);
void	stack_rotate(t_list **stack);
void	stack_rotate_reverse(t_list **stack);
void	operate(t_list **stack_a, t_list **stack_b, t_list **op_set, char *op);
void	sort_lower(t_list **stack_a, t_list **stack_b, t_list **op_set);
void	sort_stack(t_list **stack_a, t_list **stack_b, t_list **op_set);
size_t	find_order(int *sorted_arr, int find, size_t len);
int		order_distance(int a, int b, int *sorted_arr, size_t len);
int		min_dist(int arr[3]);
int		min_dist_sorted(int arr[3], int max_a);
int		min_dist_r(int arr[3]);
void	select_pa(t_list **stack_a, t_list **stack_b, t_list **op_set, int n);
void	select_ra(t_list **stack_a, t_list **stack_b, t_list **op_set, int n);
void	optimize_op(t_list **op_set);
void	optimize_rotate(t_list **stack_a, t_list **stack_b, t_list **op_set);

#endif