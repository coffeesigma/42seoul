/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:36:19 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/14 00:00:34 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_abs(int a);
int		ft_strcmp(char *s1, char *s2);
size_t	stacklen(t_list *stack);
void	stack_swap(t_list **stack);
void	stack_push(t_list **stack_out, t_list **stack_in);
void	stack_rotate(t_list **stack);
void	stack_rotate_reverse(t_list **stack);
void	operate(t_list **stack_a, t_list **stack_b, t_list **op_set, char *op);

#endif