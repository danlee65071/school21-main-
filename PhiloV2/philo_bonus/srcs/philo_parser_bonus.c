/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parser_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:38:10 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/15 17:38:13 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	philo_parser_bonus(int argc, char **argv, t_data *data)
{
	data->num_of_philos = ft_atoi_bonus(argv[1]);
	data->time_to_die = ft_atoi_bonus(argv[2]);
	data->time_to_eat = ft_atoi_bonus(argv[3]);
	data->time_to_sleep = ft_atoi_bonus(argv[4]);
	if (argc == 6)
		data->num_of_times_each_philo_must_eat = ft_atoi_bonus(argv[5]);
	else
		data->num_of_times_each_philo_must_eat = -1;
}
