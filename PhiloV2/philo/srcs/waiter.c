/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:26:36 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/15 12:26:37 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	waiter_loop(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos && data->is_dead != 1)
	{
		pthread_mutex_lock(&(data->mutex_meal));
		if (calculating_time(philo[i].last_time_meal) > data->time_to_die)
		{
			pthread_mutex_lock(&(data->mutex_writing));
			printf("%ld %d died\n", calculating_time(data->start_time), i);
			pthread_mutex_unlock(&(data->mutex_writing));
			data->is_dead = 1;
		}
		pthread_mutex_unlock(&(data->mutex_meal));
		usleep(100);
	}
}

void	waiter(t_data *data, t_philo *philo)
{
	int	i;

	while (data->is_all_fed_up != 1)
	{
		waiter_loop(data, philo);
		if (data->is_dead == 1)
			break ;
		i = 0;
		while (data->num_of_times_each_philo_must_eat != -1
			&& i < data->num_of_philos && philo[i].num_of_times_eat
			>= data->num_of_times_each_philo_must_eat)
			i++;
		if (i == data->num_of_philos)
			data->is_all_fed_up = 1;
	}
}
