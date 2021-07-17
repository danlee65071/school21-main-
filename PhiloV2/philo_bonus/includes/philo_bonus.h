/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:21:00 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/16 13:59:11 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef struct s_data
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
	int				is_dead;
	struct timeval	start_time;
	sem_t			*forks;
	sem_t			*sem_meal;
	sem_t			*sem_writing;
}	t_data;

typedef struct s_philo
{
	int				philo_index;
	struct timeval	last_time_meal;
	int				num_of_times_eat;
	pid_t			philo_pid;
	pthread_t		waiter_thread;
	t_data			*connect_data;
}	t_philo;

void	philo_parser_bonus(int argc, char **argv, t_data *data);
int		ft_atoi_bonus(const char *str);
int		sem_init_philo(t_data *data);
void	philo_init_bonus(t_data *data, t_philo *philo);
long	calculating_time_bonus(struct timeval time);
void	philo_time_sleep_bonus(struct timeval start_time, int time_sleep);
int		philo_proceses(t_data *data, t_philo *philo);
void	end_main_bonus(t_data *data, t_philo *philo);
int		philo_life_sem(t_data *data, t_philo *philo);
void	philo_eat_bonus(t_data *data, t_philo *philo);

#endif
