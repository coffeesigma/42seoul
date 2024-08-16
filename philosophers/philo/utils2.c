/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:16:14 by jeongbel          #+#    #+#             */
/*   Updated: 2024/08/16 10:49:24 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_printf(t_philo *philo, char *msg)
{
	if (check_is_dead(philo->info))
		return ;
	pthread_mutex_lock(&philo->info->print);
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
