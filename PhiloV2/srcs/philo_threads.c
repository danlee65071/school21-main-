/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:29:48 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/15 11:29:49 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->forks[philo->left_fork]));
	printf("%ld %d has taken a fork\n", calculating_time(data->start_time),
		   philo->philo_index);
	pthread_mutex_lock(&(data->forks[philo->right_fork]));
	printf("%ld %d has taken a fork\n", calculating_time(data->start_time),
		   philo->philo_index);
	pthread_mutex_lock(&(data->mutex_meal));
	gettimeofday(&(philo->last_time_meal), NULL);
	printf("%ld %d is eating\n", calculating_time(data->start_time),
		   philo->philo_index);
	pthread_mutex_unlock(&(data->mutex_meal));
	philo_time_sleep(data->start_time, data->time_to_eat);
	(philo->num_of_times_eat)++;
	pthread_mutex_unlock(&(data->forks[philo->right_fork]));
	pthread_mutex_unlock(&(data->forks[philo->left_fork]));
}

static void	*philo_life(void *args)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)args;
	data = philo->connect_data;
	if (philo->philo_index % 2 != 0)
		usleep(100);
	while (data->is_dead != 1)
	{
		philo_eat(data, philo);
		printf("%ld %d is sleeping\n", calculating_time(data->start_time),
			   philo->philo_index);
		philo_time_sleep(data->start_time, data->time_to_sleep);
		printf("%ld %d is thinking\n", calculating_time(data->start_time),
			   philo->philo_index);
	}
	return (NULL);
}

int	philo_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	gettimeofday(&(data->start_time), NULL);
	while (++i < data->num_of_philos)
	{
		gettimeofday(&(philo[i].last_time_meal), NULL);
		if (pthread_create(&(philo[i].philo_thread), NULL, philo_life, (void *)
				&(philo[i])) != 0)
		{
			printf("Philo thread create error!\n");
			return (1);
		}}
	return (0);
}
