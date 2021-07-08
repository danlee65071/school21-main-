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
static void	philos_forks_init(t_philo *philo);

int main(int argc, char **argv)
{
	t_philo					philo;
	int						i;
	int						thread;

	if (argc < 5 || argc > 6)
	{
		if (argc < 5)
			printf("Too few arguments!\n");
		else if (argc > 6)
			printf("Too many arguments!\n");
		return (1);
	}
	philo_parser(argc, argv, &philo);
	philo.philo_threads = malloc(sizeof(pthread_t) *
			philo.number_of_phs);
	if (philo.philo_threads == NULL)
	{
		printf("Philosophers malloc error!\n");
		return (1);
	}
	philo.forks = malloc(sizeof(int) * philo.number_of_phs);
	if (philo.forks == NULL)
	{
		printf("Forks malloc error!\n");
		return (1);
	}
	philos_forks_init(&philo);
	i = -1;
	gettimeofday(&philo.start_time, NULL);
	while (++i < philo.number_of_phs)
	{
		philo.philo_num = i;
		thread = pthread_create(&(philo.philo_threads[i]), NULL,
								life_of_philo, (void *)(&philo));
		if (thread != 0)
		{
			printf("Thread creation failed!\n");
			return (1);
		}
	}
	i = -1;
	while(++i < philo.number_of_phs)
		pthread_join(philo.philo_threads[i], NULL);
	free(philo.forks);
	free(philo.philo_threads);
	return (0);
}

static void	philos_forks_init(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->number_of_phs)
		philo->forks[i] = 1;
}

static void	*life_of_philo(void *philo_arg)
{
	int				i;
	struct timeval	current_time;
	int				num_of_time_eat;
	t_philo			*philo;

	num_of_time_eat = 0;
	philo = (t_philo *)philo_arg;
	if ((current_time.tv_sec - philo->start_time.tv_sec) * 1000 +
		current_time.tv_usec - philo->start_time.tv_usec > philo->time_to_die)
	{
		printf("%ld %d died", current_time.tv_sec * 1000 +
			current_time.tv_usec, philo->philo_num);
	}
	return (NULL);
}
