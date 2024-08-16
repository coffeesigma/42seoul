/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:16:14 by jeongbel          #+#    #+#             */
/*   Updated: 2024/08/16 12:13:57 by jeongbel         ###   ########.fr       */
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
