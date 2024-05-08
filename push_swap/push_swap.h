/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:52:42 by jeongbel          #+#    #+#             */
/*   Updated: 2024/05/08 16:03:53 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

void	exit_error(void);
char	*make_arr(t_list *stack);
void	bubble_sort(int *arr);
int		ctoi(char *content);
void	stack_add(t_list **stack, char **content);
t_list	*make_stack(int argc, char **argv);
size_t	stacklen(t_list *stack);
void	stack_swap(t_list **stack);
void	stack_push(t_list **stack_out, t_list **stack_in);
void	stack_rotate(t_list **stack);
void	stack_rotate_reverse(t_list **stack);
void	operate(t_list **stack_a, t_list **stack_b, char *op);

#endif