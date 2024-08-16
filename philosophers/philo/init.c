/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 05:36:41 by jeongbel          #+#    #+#             */
/*   Updated: 2024/08/16 10:41:25 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutexes(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philos)
	{
		if (pthread_mutex_init(&info->forks[i], NULL)
			|| pthread_mutex_init(&info->philos[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&info->print, NULL)
		|| pthread_mutex_init(&info->full, NULL)
		|| pthread_mutex_init(&info->dead, NULL))
		return (1);
	return (0);
}

static int	init_philo(t_philo *philo, t_info *info, int id)
{
	philo->id = id;
	philo->num_of_eat = 0;
	philo->left_fork = &info->forks[id - 1];
	philo->right_fork = &info->forks[id % info->num_of_philos];
	philo->info = info;
	gettimeofday(&philo->last_meal, NULL);
	philo->eat_count = 0;
	return (0);
}

int	init_info(t_info *info, int argc, char **argv)
{
	info->num_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_of_must_eat = ft_atoi(argv[5]);
	else
		info->num_of_must_eat = -1;
	info->is_dead = 0;
	info->is_full = 0;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_of_philos);
	info->philos = malloc(sizeof(pthread_mutex_t) * info->num_of_philos);
	if (!info->forks || !info->philos)
		return (1);
	if (init_mutexes(info))
		return (1);
	gettimeofday(&info->start, NULL);
	return (0);
}

int	init_philos(t_philo **philos, t_info *info)
{
	int	i;

	i = 0;
	*philos = malloc(sizeof(t_philo) * info->num_of_philos);
	if (!*philos)
		return (1);
	while (i < info->num_of_philos)
	{
		if (init_philo(&(*philos)[i], info, i + 1))
			return (1);
		if (pthread_create(&(*philos)[i].thread, NULL,
			philo_routine, &(*philos)[i]))
			return (1);
		i++;
	}
	return (0);
}
