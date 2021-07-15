/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:45:50 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/15 10:45:51 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		philo[i].philo_index = i;
		if (i == data->num_of_philos - 1)
		{
			philo[i].left_fork = i;
			philo[i].right_fork = 0;
		}
		else
		{
			philo[i].left_fork = i;
			philo[i].right_fork = i + 1;
		}
		philo[i].num_of_times_eat = 0;
		philo[i].connect_data = data;
	}
}
