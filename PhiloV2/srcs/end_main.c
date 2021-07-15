/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:00:54 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/15 13:00:55 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_main(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
		pthread_detach(philo[i].philo_thread);
	i = -1;
	while (++i < data->num_of_philos)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->mutex_meal));
}
