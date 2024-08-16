/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 04:50:09 by jeongbel          #+#    #+#             */
/*   Updated: 2024/08/16 10:16:29 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	if (!s)
		return (0);
	size = 0;
	while (s[size])
		size++;
	return (size);
}

int	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		number;

	sign = 1;
	number = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += sign * (str[i] - '0');
		i++;
	}
	return (number);
}

int	get_time(struct timeval start)
{
	struct timeval	now;
	int				time;

	gettimeofday(&now, NULL);
	time = (now.tv_sec - start.tv_sec) * 1000
		+ (now.tv_usec - start.tv_usec) / 1000;
	return (time);
}

void	philo_usleep(int time, t_info *info)
{
	struct timeval	start;

	if (info->is_dead)
		return ;
	gettimeofday(&start, NULL);
	usleep(time * 0.7 * 1000);
	while (get_time(start) < time)
		usleep(100);
}
