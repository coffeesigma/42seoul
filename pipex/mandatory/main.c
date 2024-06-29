/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:52:43 by jeongbel          #+#    #+#             */
/*   Updated: 2024/06/25 17:02:37 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	if (argc != 5)
	{
		printf("argv[0]: %s\n", argv[0]);
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		return (1);
	}
	return (0);
}