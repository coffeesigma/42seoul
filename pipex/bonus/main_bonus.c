/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:53:31 by jeongbel          #+#    #+#             */
/*   Updated: 2024/06/25 17:02:44 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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