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

static void	*life_of_philo(void *philo);
int			philo_eat(t_philo_args *philo);
void		*waiter_vision(void *philo_args);

int	main(int argc, char **argv)
{
	t_philo					philo;
	t_philo_args			*philo_args;
	pthread_t				waiter;

	philo_args = NULL;
	if (start_main(argc, argv, &philo, &philo_args) != 0)
		return (1);
	philo_call(&philo, &philo_args, life_of_philo);
	waiter = NULL;
	if (waiter_call(waiter, waiter_vision, philo_args) != 0)
		return (1);
	end_main(philo_args, philo);
	return (0);
}

static void	*life_of_philo(void *philo_arg)
{
	t_philo_args	*philo;
	t_philo			*p;

	philo = (t_philo_args *)philo_arg;
	p = philo->connect;
	while (1)
	{
		if (philo_eat(philo) != 0)
			break ;
		pthread_mutex_lock(&(p->all_philos_ate_full));
		if (p->num_of_philo_ate == p->number_of_phs)
			break ;
		pthread_mutex_unlock(&(p->all_philos_ate_full));
		printf("%ld %d is sleeping\n", calculating_time(p->start_time),
			   philo->philo_index);
		philo_time_sleep(p->start_time, p->time_to_sleep);
		printf("%ld %d is thinking\n", calculating_time(p->start_time),
			   philo->philo_index);
	}
	return (NULL);
}

int	philo_eat(t_philo_args *philo)
{
	t_philo	*p;

	p = philo->connect;
	pthread_mutex_lock(&(p->all_philos_ate_full));
	if (p->num_of_philo_ate == p->number_of_phs)
		return (1);
	pthread_mutex_unlock(&(p->all_philos_ate_full));
	pthread_mutex_lock(&(p->forks[philo->left_fork]));
	printf("%ld %d has taken a fork\n", calculating_time(p->start_time),
		   philo->philo_index);
	pthread_mutex_lock(&(p->forks[philo->right_fork]));
	printf("%ld %d has taken a fork\n", calculating_time(p->start_time),
		   philo->philo_index);
	gettimeofday(&(philo->time_last_meal), NULL);
	printf("%ld %d is eating\n", calculating_time(p->start_time),
		philo->philo_index);
	philo_time_sleep(p->start_time, p->time_to_eat);
	(philo->number_of_time_eat)++;
	pthread_mutex_unlock(&(p->forks[philo->right_fork]));
	pthread_mutex_unlock(&(p->forks[philo->left_fork]));
	return (0);
}

void	*waiter_vision(void *philo_args)
{
	t_philo_args	*philo;
	t_philo			*p;
	int				philo_is_dead;

	philo = (t_philo_args *)philo_args;
	p = philo->connect;
	philo_is_dead = 0;
	while (1)
	{
		waiter_proc(p, philo, &philo_is_dead);
		if (philo_is_dead == 1 || p->num_of_philo_ate == p->number_of_phs)
			break ;
	}
	return (NULL);
}
