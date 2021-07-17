/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_main_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 21:35:15 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/15 21:35:17 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	end_main_bonus(t_data *data, t_philo *philo)
{
	int	i;
	int	wait_status;

	i = -1;
	while (++i < data->num_of_philos)
	{
		waitpid(-1, &wait_status, 0);
		if (wait_status != 0)
		{
			i = -1;
			while (++i < data->num_of_philos)
				kill(philo->philo_pid, SIGTERM);
			break ;
		}
	}
	sem_close(data->forks);
	sem_close(data->sem_writing);
	sem_close(data->sem_meal);
	sem_unlink("forks");
	sem_unlink("meal");
	sem_unlink("writing");
}
