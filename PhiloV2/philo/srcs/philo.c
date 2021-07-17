/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:50:43 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/05 17:51:30 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philo[200];

	if (argc != 5 && argc != 6)
	{
		printf("Wrong number of arguments!\n");
		return (1);
	}
	philo_parser(argc, argv, &data);
	philo_init(&data, philo);
	if (forks_init(&data) != 0)
		return (1);
	if (philo_threads(&data, philo) != 0)
		return (1);
	waiter(&data, philo);
	end_main(&data, philo);
	return (0);
}
