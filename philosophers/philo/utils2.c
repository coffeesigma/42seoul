/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:16:14 by jeongbel          #+#    #+#             */
/*   Updated: 2024/08/16 10:16:38 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_printf(t_philo *philo, char *msg)
{
	if (philo->info->is_dead)
		return ;
	pthread_mutex_lock(&philo->info->print);
	printf("%d %d %s\n", get_time(philo->info->start), philo->id, msg);
	pthread_mutex_unlock(&philo->info->print);
	usleep(100);
}
