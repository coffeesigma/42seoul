/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:16:14 by jeongbel          #+#    #+#             */
/*   Updated: 2024/08/17 19:33:21 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_printf(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->print);
	if (check_is_dead(philo->info))
	{
		pthread_mutex_unlock(&philo->info->print);
		return ;
	}
	printf("%d %d %s\n", get_time(philo->info->start), philo->id, msg);
	pthread_mutex_unlock(&philo->info->print);
	usleep(100);
}

int	check_is_dead(t_info *info)
{
	pthread_mutex_lock(&info->dead);
	if (info->is_dead)
	{
		pthread_mutex_unlock(&info->dead);
		return (1);
	}
	pthread_mutex_unlock(&info->dead);
	return (0);
}

void	free_all(t_philo *philos, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philos)
	{
		pthread_mutex_destroy(&info->philos[i]);
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->dead);
	pthread_mutex_destroy(&info->full);
	free(philos);
	free(info->forks);
	free(info->philos);
}
