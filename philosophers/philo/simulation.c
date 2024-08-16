/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:24:38 by jeongbel          #+#    #+#             */
/*   Updated: 2024/08/16 10:43:05 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_is_dead(t_philo *philo)
{
	int	time_diff;

	time_diff = get_time(philo->last_meal);
	if (time_diff > philo->info->time_to_die)
	{
		pthread_mutex_lock(&philo->info->dead);
		philo->info->is_dead = 1;
		pthread_mutex_lock(&philo->info->print);
		printf("%d %d died\n", get_time(philo->info->start), philo->id);
		pthread_mutex_unlock(&philo->info->print);
		pthread_mutex_unlock(&philo->info->dead);
		return (1);
	}
	return (0);
}

static void	monitor(t_philo *philos, t_info *info)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < info->num_of_philos)
		{
			if (philo_is_dead(&philos[i]))
				return ;
			if (info->is_full == info->num_of_philos)
				return ;
			i++;
		}
		usleep(10);
	}
}

int	start_simulation(t_philo *philos, t_info *info)
{
	int	i;

	monitor(philos, info);
	i = 0;
	while (i < info->num_of_philos)
	{
		if (pthread_join(philos[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}
