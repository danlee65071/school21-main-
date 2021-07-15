/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:11:06 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/15 11:11:08 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	forks_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
		{
			printf("Forks init error!\n");
			return (1);
		}
	if (pthread_mutex_init(&(data->mutex_meal), NULL) != 0)
	{
		printf("Mutex init error!\n");
		return (1);
	}
	return (0);
}
