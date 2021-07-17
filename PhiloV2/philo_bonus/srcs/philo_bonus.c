/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:19:46 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/15 17:19:47 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philo[200];

	if (argc != 5 && argc != 6)
	{
		printf("Wrong number of arguments!\n");
		return (1);
	}
	philo_parser_bonus(argc, argv, &data);
	philo_init_bonus(&data, philo);
	sem_init_philo(&data);
	philo_proceses(&data, philo);
	end_main_bonus(&data, philo);
	return (0);
}
