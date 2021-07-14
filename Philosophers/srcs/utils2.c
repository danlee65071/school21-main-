/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:37:43 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/14 10:37:45 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_time_sleep(struct timeval start_time, int time_sleep)
{
	long	till_time;

	till_time = calculating_time(start_time) + time_sleep;
	while (calculating_time(start_time) < till_time)
		usleep(100);
}

void	destroy(t_philo_args *philo_args, t_philo philo, int j)
{
	pthread_detach(philo_args[j].philo_thread);
	pthread_mutex_destroy(&(philo.forks[j]));
	pthread_mutex_destroy(&(philo_args[j].dead_mutex));
}

int	parser_preapre(int argc)
{
	if (argc < 5 || argc > 6)
	{
		if (argc < 5)
			printf("Too few arguments!\n");
		else if (argc > 6)
			printf("Too many arguments!\n");
		return (1);
	}
	return (0);
}

int	philo_call(t_philo *philo, t_philo_args **philo_args,
					  void *(*life_of_philo)(void *))
{
	int	i;

	i = -1;
	gettimeofday(&(philo->start_time), NULL);
	while (++i < philo->number_of_phs)
	{
		gettimeofday(&((*philo_args)[i].time_last_meal), NULL);
		if (pthread_create(&((*philo_args)[i].philo_thread), NULL,
			life_of_philo, (void *)(&((*philo_args)[i]))) != 0)
		{
			printf("Thread creation failed!\n");
			return (1);
		}
		usleep(100);
	}
	return (0);
}

int	waiter_call(pthread_t waiter, void *(*waiter_vision)(void *),
					   t_philo_args *philo_args)
{
	if (pthread_create(&waiter, NULL, waiter_vision, (void *)philo_args) != 0)
	{
		printf("Thread creation failed!\n");
		return (1);
	}
	pthread_join(waiter, NULL);
	return (0);
}
