/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:30:46 by jeongbel          #+#    #+#             */
/*   Updated: 2024/07/31 19:49:01 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	make_pipe(t_info *info)
{
	int	i;

	i = 0;
	info->fds = (int **)malloc(sizeof(int *) * (info->cmd_num - 1));
	if (!info->fds)
		error_exit("malloc");
	while (i < info->cmd_num - 1)
	{
		info->fds[i] = (int *)malloc(sizeof(int) * 2);
		if (!info->fds[i])
			error_exit("malloc");
		if (pipe(info->fds[i]) == -1)
			error_exit("pipe");
		i++;
	}
}

static void	open_file(t_info *info, int argc, char **argv)
{
	info->in_fd = open(argv[1], O_RDONLY);
	if (info->in_fd == -1)
		error_exit("open");
	info->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info->out_fd == -1)
		error_exit("open");
}

void	init_info(t_info *info, int argc, char **argv, char **envp)
{
	open_file(info, argc, argv);
	make_cmd(info, argc, argv, envp);
	make_pipe(info);
	info->idx = -1;
}
