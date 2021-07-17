/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:20:11 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/15 19:20:13 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	philo_init_bonus(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		philo[i].philo_index = i;
		philo[i].num_of_times_eat = 0;
		philo[i].connect_data = data;
	}
}
