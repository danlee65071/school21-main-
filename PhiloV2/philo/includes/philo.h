/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:51:44 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/16 13:53:49 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
	int				is_dead;
	int				is_all_fed_up;
	struct timeval	start_time;
	pthread_mutex_t	forks[200];
	pthread_mutex_t	mutex_meal;
	pthread_mutex_t	mutex_writing;
}	t_data;

typedef struct s_philo
{
	int				philo_index;
	int				left_fork;
	int				right_fork;
	struct timeval	last_time_meal;
	int				num_of_times_eat;
	pthread_t		philo_thread;
	t_data			*connect_data;
}	t_philo;

int		ft_atoi(const char *str);
void	philo_parser(int argc, char **argv, t_data *data);
void	philo_init(t_data *data, t_philo *philo);
int		forks_init(t_data *data);
long	calculating_time(struct timeval time);
void	philo_time_sleep(struct timeval start_time, int time_sleep);
int		philo_threads(t_data *data, t_philo *philo);
void	waiter(t_data *data, t_philo *philo);
void	end_main(t_data *data, t_philo *philo);

#endif
