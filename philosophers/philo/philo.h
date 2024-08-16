/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:30:35 by jeongbel          #+#    #+#             */
/*   Updated: 2024/08/16 09:38:22 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_info
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	int				is_dead;
	int				is_full;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	*philos;
	pthread_mutex_t	full;
	struct timeval	start;
}	t_info;

typedef struct s_philo
{
	int				id;
	int				num_of_eat;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_info			*info;
	struct timeval	last_meal;
	int				eat_count;
}	t_philo;

// utils.c
size_t	ft_strlen(const char *s);
int		print_error(char *msg);
int		ft_atoi(const char *str);
int		get_time(struct timeval start);
void	philo_usleep(int time, t_info *info);
void	philo_printf(t_philo *philo, char *msg);
// init.c
int		init_info(t_info *info, int argc, char **argv);
int		init_philos(t_philo **philos, t_info *info);
// philo.c
void	*philo_routine(void *arg);
// simulation.c
int		start_simulation(t_philo *philos, t_info *info);
//int	philo_is_full(t_philo *philo);

#endif