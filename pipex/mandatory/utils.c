/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:50:37 by jeongbel          #+#    #+#             */
/*   Updated: 2024/07/31 21:22:35 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *msg)
{
	perror(msg);
	exit(1);
}

void	dup2_with_error(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		error_exit("dup2");
}
