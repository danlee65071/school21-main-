/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:04:05 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/15 18:04:07 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	sem_init_philo(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("writing");
	sem_unlink("meal");
	data->forks = sem_open("forks", O_CREAT, S_IRWXU, data->num_of_philos);
	data->sem_meal = sem_open("meal", O_CREAT, S_IRWXU, 1);
	data->sem_writing = sem_open("writing", O_CREAT, S_IRWXU, 1);
	if (data->forks <= 0 || data->sem_meal <= 0
		|| data->sem_writing <= 0)
	{
		printf("Sems init error!\n");
		return (1);
	}
	return (0);
}
