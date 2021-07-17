/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:29:14 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/15 20:29:16 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	waiter_loop_bonus(t_data *data, t_philo *philo)
{
	while (1)
	{
		sem_wait(data->sem_meal);
		if (calculating_time_bonus(philo->last_time_meal) > data->time_to_die)
		{
			sem_wait(data->sem_writing);
			printf("%ld %d died\n", calculating_time_bonus(data->start_time),
				   philo->philo_index);
			sem_post(data->sem_writing);
			sem_wait(data->sem_writing);
			data->is_dead = 1;
		}
		sem_post(data->sem_meal);
		if (data->is_dead == 1)
			exit(1);
		usleep(1000);
		if (data->num_of_times_each_philo_must_eat != -1
			&& philo->num_of_times_eat
			   >= data->num_of_times_each_philo_must_eat)
			exit (0);
	}
}

static void	*waiter_bonus(void *args)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)args;
	data = philo->connect_data;
	waiter_loop_bonus(data, philo);
	return (NULL);
}

void	philo_eat_bonus(t_data *data, t_philo *philo)
{
	usleep(100);
	sem_wait(data->forks);
	sem_wait(data->sem_writing);
	printf("%ld %d has taken a fork\n",
		   calculating_time_bonus(data->start_time), philo->philo_index);
	sem_post(data->sem_writing);
	sem_wait(data->forks);
	sem_wait(data->sem_writing);
	printf("%ld %d has taken a fork\n",
		   calculating_time_bonus(data->start_time), philo->philo_index);
	sem_post(data->sem_writing);
	sem_wait(data->sem_meal);
	sem_wait(data->sem_writing);
	printf("%ld %d is eating\n", calculating_time_bonus(data->start_time),
		   philo->philo_index);
	sem_post(data->sem_writing);
	gettimeofday(&(philo->last_time_meal), NULL);
	sem_post(data->sem_meal);
	philo_time_sleep_bonus(data->start_time, data->time_to_eat);
	(philo->num_of_times_eat)++;
	sem_post(data->forks);
	sem_post(data->forks);
}

static void	philo_life_bonus(t_data *data, t_philo *philo)
{
	int	waiter_thread;

	gettimeofday(&(philo->last_time_meal), NULL);
	waiter_thread = pthread_create(&(philo->waiter_thread), NULL, waiter_bonus,
			(void *)(philo));
	if (waiter_thread != 0)
	{
		printf("Waiter thread create error!\n");
		exit (1);
	}
	if (philo->philo_index % 2 != 0)
		usleep(15000);
	while (data->is_dead != 1)
	{
		if (philo_life_sem(data, philo) == 1)
			break ;
	}
	pthread_join(philo->waiter_thread, NULL);
	if (data->is_dead == 1)
		exit (0);
	exit(0);
}

int	philo_proceses(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	gettimeofday(&(data->start_time), NULL);
	while (++i < data->num_of_philos)
	{
		philo[i].philo_pid = fork();
		if (philo[i].philo_pid == -1)
		{
			printf("Fork error!\n");
			exit (1);
		}
		if (philo[i].philo_pid == 0)
			philo_life_bonus(data, &(philo[i]));
		usleep(100);
	}
	return (0);
}
