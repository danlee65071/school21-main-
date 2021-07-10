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
void		philo_eat(t_philo *philo, struct timeval current_time);

int main(int argc, char **argv)
{
	t_philo					philo;
	int						i;
	int						thread;
	t_philo_args			*tmp_philo_arg;

	if (argc < 5 || argc > 6)
	{
		if (argc < 5)
			printf("Too few arguments!\n");
		else if (argc > 6)
			printf("Too many arguments!\n");
		return (1);
	}
	philo_parser(argc, argv, &philo);
	if (philo_init(&philo) != 0)
		return (1);
	if (philos_forks_init(&philo) != 0)
		return (1);
	i = -1;
	gettimeofday(&philo.start_time, NULL);
	tmp_philo_arg = philo.philo;
	while (++i < philo.number_of_phs)
	{
		thread = pthread_create(&(philo.philo[i].philo_thread), NULL,
								life_of_philo, (void *)(&philo));
		if (thread != 0)
		{
			printf("Thread creation failed!\n");
			return (1);
		}
		philo.philo++;
	}
	i = -1;
	while(++i < philo.number_of_phs)
		pthread_join(philo.philo[i].philo_thread, NULL);
	free(philo.forks);
	free(philo.philo);
	return (0);
}

static void	*life_of_philo(void *philo_arg)
{
//	int				i;
	struct timeval	current_time;
	int				num_of_time_eat;
	t_philo			*philo;

	num_of_time_eat = 0;
	philo = (t_philo *)philo_arg;
	gettimeofday(&current_time, NULL);
	while (1)
	{
		philo_eat(philo, current_time);
	}
	return (NULL);
}

void	philo_eat(t_philo *philo, struct timeval current_time)
{
//	pthread_mutex_t	fork_guard_deadlock;

//	pthread_mutex_init(&fork_guard_deadlock, NULL);
//	pthread_mutex_lock(&fork_guard_deadlock);
	pthread_mutex_lock(&(philo->forks[philo->philo->left_fork]));
	pthread_mutex_lock(&(philo->forks[philo->philo->right_fork]));
//	pthread_mutex_unlock(&fork_guard_deadlock);
	printf("%ld %d is eating\n", current_time.tv_sec * 1000 +
		current_time.tv_usec, philo->philo->philo_index);
	usleep(philo->time_to_eat);
	sleep(1);
	pthread_mutex_unlock(&(philo->forks[philo->philo->left_fork]));
	pthread_mutex_unlock(&(philo->forks[philo->philo->right_fork]));
}
