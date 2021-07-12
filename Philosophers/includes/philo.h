/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:51:44 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/05 17:52:26 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int				number_of_phs;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				num_of_philo_ate;
	pthread_mutex_t	*forks;
	struct timeval	start_time;
} t_philo;

typedef struct	s_philo_args
{
	pthread_t		philo_thread;
	int				philo_index;
	int				right_fork;
	int 			left_fork;
	int				is_dead;
	int				number_of_time_eat;
	struct timeval	time_last_meal;
	t_philo			*connect;
} t_philo_args;

int		ft_atoi(const char *str);
void	philo_parser(int argc, char **argv, t_philo *philo);
int		philos_forks_init(t_philo *philo);
int		philo_init(t_philo_args **philo_args, t_philo *connect);

#endif
