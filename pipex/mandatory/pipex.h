/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:49:55 by jeongbel          #+#    #+#             */
/*   Updated: 2024/07/31 21:22:06 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_cmd
{
	char	*cmd;
	char	**argv;
}	t_cmd;

typedef struct s_info
{
	int		idx;
	int		cmd_num;
	pid_t	pid;
	int		**fds;
	t_cmd	*cmd;
	char	**path_list;
	int		in_fd;
	int		out_fd;
}	t_info;

void	error_exit(char *msg);
void	dup2_with_error(int oldfd, int newfd);
void	make_cmd(t_info *info, int argc, char **argv, char **envp);
void	init_info(t_info *info, int argc, char **argv, char **envp);
void	exec_cmds(t_info *info);

#endif