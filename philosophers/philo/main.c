/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:24:06 by jeongbel          #+#    #+#             */
/*   Updated: 2024/08/14 17:04:39 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Invalid arguments\n");
		return (1);
	}
	if (init_info(&info, argc, argv))
	{
		printf("Error: Invalid arguments\n");
		return (1);
	}
	if (init_philos(&info))
	{
		printf("Error: Failed to initialize philosophers\n");
		return (1);
	}
	if (start_simulation(&info))
	{
		printf("Error: Failed to start simulation\n");
		return (1);
	}
	return (0);
}
