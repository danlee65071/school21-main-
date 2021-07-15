/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:20:44 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/14 14:20:47 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_main(int argc, char **argv, t_philo *philo, t_philo_args **philo_args)
{
	if (parser_preapre(argc) != 0)
		return (1);
	if (philo_parser(argc, argv, philo) != 0)
		return (1);
	if (philos_forks_init(philo) != 0)
		return (1);
	if (philo_init(philo_args, philo) != 0)
		return (1);
	return (0);
}

int	end_main(t_philo_args *philo_args, t_philo philo)
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		if (i == philo.number_of_phs)
			i = 0;
		if ((philo_args[i].is_dead == 1)
			|| (philo.num_of_philo_ate == philo.number_of_phs))
		{
			j = -1;
			while (++j < philo.number_of_phs)
				destroy(philo_args, philo, j);
			pthread_mutex_destroy(&(philo.all_philos_ate_full));
			break ;
		}
		i++;
	}
	free(philo.forks);
	free(philo_args);
	return (0);
}

void	waiter_proc(t_philo *p, t_philo_args *philo, int *philo_is_dead)
{
	int	i;

	i = -1;
	while (++i < p->number_of_phs)
	{
		pthread_mutex_lock(&(philo[i].dead_mutex));
		if (calculating_time(philo[i].time_last_meal) > p->time_to_die)
		{
			philo[i].is_dead = 1;
			*philo_is_dead = 1;
			printf("%ld %d died\n", calculating_time(p->start_time),
				   philo[i].philo_index);
			break ;
		}
		pthread_mutex_unlock(&(philo[i].dead_mutex));
		if (philo[i].number_of_time_eat
			== p->number_of_times_each_philosopher_must_eat
			&& philo[i].is_eat_full == 0)
		{
			(p->num_of_philo_ate)++;
			philo[i].is_eat_full = 1;
		}
		if (p->num_of_philo_ate == p->number_of_phs)
			break ;
	}
}

int	philo_init_helper(t_philo *connect, t_philo_args **philo_args)
{
	int	i;

	i = -1;
	while (++i < connect->number_of_phs)
	{
		(*philo_args)[i].philo_index = i;
		if (i == connect->number_of_phs - 1)
		{
			(*philo_args)[i].left_fork = i;
			(*philo_args)[i].right_fork = 0;
		}
		else
		{
			(*philo_args)[i].left_fork = i;
			(*philo_args)[i].right_fork = i + 1;
		}
		(*philo_args)[i].number_of_time_eat = 0;
		(*philo_args)[i].is_dead = 0;
		(*philo_args)[i].is_eat_full = 0;
		if (pthread_mutex_init((&(*philo_args)[i].dead_mutex), NULL) != 0)
			return (1);
	}
	return (0);
}
