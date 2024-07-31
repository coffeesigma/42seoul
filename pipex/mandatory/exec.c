/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 02:47:33 by jeongbel          #+#    #+#             */
/*   Updated: 2024/07/31 20:01:50 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_child(t_info *info, int idx)
{
	if (idx == 0)
	{
		dup2(info->in_fd, 0);
		close(info->in_fd);
	}
	else
	{
		dup2(info->fds[idx - 1][0], 0);
		close(info->fds[idx - 1][1]);
		close(info->fds[idx - 1][0]);
	}
	if (idx == info->cmd_num - 1)
	{
		dup2(info->out_fd, 1);
		close(info->out_fd);
	}
	else
	{
		dup2(info->fds[idx][1], 1);
		close(info->fds[idx][0]);
		close(info->fds[idx][1]);
	}
	execve(info->cmd[idx].cmd, info->cmd[idx].argv, info->path_list);
	error_exit("execve");
}

static void	exec_cmd(t_info *info)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit("fork");
	if (pid == 0)
		exec_child(info, info->idx);
	else
	{
		if (info->idx == 0)
			close(info->in_fd);
		else
		{
			close(info->fds[info->idx - 1][0]);
			close(info->fds[info->idx - 1][1]);
		}
		if (info->idx == info->cmd_num - 1)
			close(info->out_fd);
		else
			close(info->fds[info->idx][1]);
	}
}

void	exec_cmds(t_info *info)
{
	while (++info->idx < info->cmd_num)
		exec_cmd(info);
	while (--info->idx >= 0)
		wait(NULL);
}
