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
	pthread_mutex_t all_philos_ate_full;
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
	int				is_eat_full;
	pthread_mutex_t	dead_mutex;
	struct timeval	time_last_meal;
	t_philo			*connect;
} t_philo_args;

int		ft_atoi(const char *str);
int		philo_parser(int argc, char **argv, t_philo *philo);
int		philos_forks_init(t_philo *philo);
int		philo_init(t_philo_args **philo_args, t_philo *connect);
long	calculating_time(struct timeval time);
void	philo_time_sleep(struct timeval start_time, int time_sleep);
void	destroy(t_philo_args *philo_args, t_philo philo, int j);
int		parser_preapre(int argc);
int		philo_call(t_philo *philo, t_philo_args **philo_args,
					  void *(*life_of_philo)(void *));
int		waiter_call(pthread_t waiter, void *(*waiter_vision)(void *),
					   t_philo_args *philo_args);
int		start_main(int argc, char **argv,t_philo *philo, t_philo_args
	**philo_args);
int		end_main(t_philo_args *philo_args, t_philo philo);
void	waiter_proc(t_philo *p, t_philo_args *philo, int *philo_is_dead);
int		philo_init_helper(t_philo *connect, t_philo_args **philo_args);

#endif
