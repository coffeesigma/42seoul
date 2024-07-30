/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:52:43 by jeongbel          #+#    #+#             */
/*   Updated: 2024/07/31 03:10:44 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	if (argc < 5)
	{
		ft_putstr_fd("Error: invalid arguments\n", 2);
		return (1);
	}
	init_info(&info, argc, argv, envp);
	exec_cmds(&info);
	return (0);
}
