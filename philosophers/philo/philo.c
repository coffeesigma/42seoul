/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 06:34:51 by jeongbel          #+#    #+#             */
/*   Updated: 2024/08/16 12:32:46 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_eat(t_philo *philo)
{
	if (philo->id % 2)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	philo_printf(philo, "has taken a fork");
	if (philo->info->num_of_philos == 1)
		return (1);
	if (philo->id % 2)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	philo_printf(philo, "has taken a fork");
	gettimeofday(&philo->last_meal, NULL);
	philo_printf(philo, "is eating");
	philo->eat_count++;
	philo_usleep(philo->info->time_to_eat, philo->info);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

static int	philo_sleep(t_philo *philo)
{
	philo_printf(philo, "is sleeping");
	philo_usleep(philo->info->time_to_sleep, philo->info);
	return (0);
}

static int	philo_think(t_philo *philo)
{
	philo_printf(philo, "is thinking");
	usleep(50);
	return (0);
}

static int	philo_is_full(t_philo *philo)
{
	if (philo->info->num_of_must_eat != -1
		&& philo->eat_count == philo->info->num_of_must_eat)
	{
		pthread_mutex_lock(&philo->info->full);
		philo->info->is_full++;
		pthread_mutex_unlock(&philo->info->full);
		return (1);
	}
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(500);
	while (check_is_dead(philo->info) == 0)
	{
		if (philo_eat(philo))
		{
			pthread_mutex_unlock(philo->right_fork);
			return (NULL);
		}
		philo_is_full(philo);
		usleep(50);
		philo_sleep(philo);
		usleep(50);
		philo_think(philo);
	}
	return (NULL);
}
