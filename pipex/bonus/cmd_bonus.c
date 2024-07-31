/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:27:32 by jeongbel          #+#    #+#             */
/*   Updated: 2024/07/31 19:47:43 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**get_path(char **envp)
{
	size_t	i;
	char	**path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path = ft_split(envp[i] + 5, ':');
	if (!path)
		error_exit("ft_split");
	return (path);
}

static t_cmd	get_cmd(char *arg, char **path)
{
	size_t	i;
	t_cmd	cmd;

	cmd.argv = ft_split(arg, ' ');
	if (!cmd.argv)
		error_exit("ft_split");
	i = 0;
	while (path[i])
	{
		cmd.cmd = ft_strjoin("/", cmd.argv[0]);
		cmd.cmd = ft_strjoin(path[i], cmd.cmd);
		if (!cmd.cmd)
			error_exit("ft_strjoin");
		if (!access(cmd.cmd, X_OK))
			return (cmd);
		free(cmd.cmd);
		i++;
	}
	ft_putstr_fd("Error: command not found\n", 2);
	exit(1);
}

void	make_cmd(t_info *info, int argc, char **argv, char **envp)
{
	info->cmd_num = argc - 3;
	info->path_list = get_path(envp);
	info->cmd = (t_cmd *)malloc(sizeof(t_cmd) * info->cmd_num);
	if (!info->cmd)
		error_exit("malloc");
	info->idx = -1;
	while (++info->idx < info->cmd_num)
		info->cmd[info->idx] = get_cmd(argv[info->idx + 2], info->path_list);
}
