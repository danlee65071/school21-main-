/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:30:24 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/08 18:30:25 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_parser(int argc, char **argv, t_philo *philo)
{
	philo->number_of_phs = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		philo->number_of_times_each_philosopher_must_eat = -1;
	philo->num_of_philo_ate = 0;
	if (pthread_mutex_init(&(philo->all_philos_ate_full), NULL) != 0)
	{
		printf("Mutex init error!\n");
		return (1);
	}
	return (0);
}
