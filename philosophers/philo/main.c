/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:24:06 by jeongbel          #+#    #+#             */
/*   Updated: 2024/08/16 09:53:30 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philos;

	if (argc != 5 && argc != 6)
		return (print_error("Error: Invalid number of arguments\n"));
	if (init_info(&info, argc, argv))
		return (print_error("Error: Failed to initialize info\n"));
	if (init_philos(&philos, &info))
		return (print_error("Error: Failed to initialize philos\n"));
	if (start_simulation(philos, &info))
		return (print_error("Error: Failed to start simulation\n"));
	return (0);
}
