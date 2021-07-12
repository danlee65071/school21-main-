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
void		philo_eat(t_philo_args *philo);
void	*waiter_vision(void *philo_args);

int main(int argc, char **argv)
{
	t_philo					philo;
	int						i;
	int						thread;
	t_philo_args			*philo_args;
	pthread_t				waiter;
	int						j;

	if (argc < 5 || argc > 6)
	{
		if (argc < 5)
			printf("Too few arguments!\n");
		else if (argc > 6)
			printf("Too many arguments!\n");
		return (1);
	}
	philo_parser(argc, argv, &philo);
	if (philos_forks_init(&philo) != 0)
		return (1);
	if (philo_init(&philo_args, &philo) != 0)
		return (1);
	i = -1;
	gettimeofday(&(philo.start_time), NULL);
	while (++i < philo.number_of_phs)
	{
		gettimeofday(&(philo_args[i].time_last_meal), NULL);
		thread = pthread_create(&(philo_args[i].philo_thread), NULL,
								life_of_philo, (void *)(&(philo_args[i])));
		if (thread != 0)
		{
			printf("Thread creation failed!\n");
			return (1);
		}
		usleep(100);
	}
	thread = pthread_create(&waiter, NULL, waiter_vision, (void *)philo_args);
	if (thread != 0)
	{
		printf("Thread creation failed!\n");
		return (1);
	}
	pthread_join(waiter, NULL);
//	i = -1;
//	while(++i < philo.number_of_phs)
//		pthread_join(philo_args[i].philo_thread, NULL);
	i = 0;
	while (1)
	{
		if (i == philo.number_of_phs)
			i = 0;
		if (philo_args[i].is_dead == 1)
		{
			j = -1;
			while (++j < philo.number_of_phs)
				pthread_detach(philo_args[i].philo_thread);
			break ;
		}
		else if (philo.num_of_philo_ate == philo.number_of_phs)
		{
			j = -1;
			while (++j < philo.number_of_phs)
				pthread_detach(philo_args[i].philo_thread);
			break ;
		}
//		if (philo_args[i].number_of_time_eat == philo.number_of_times_each_philosopher_must_eat)
//			philo.num_of_philo_ate++;
//		if (philo.num_of_philo_ate == philo.number_of_phs)
//			break ;
		i++;
	}
	free(philo.forks);
	free(philo_args);
	return (0);
}

static void	*life_of_philo(void *philo_arg)
{
	int				i;
	struct timeval	current_time;
	t_philo_args 	*philo;
	t_philo 		*p;

	philo = (t_philo_args *)philo_arg;
	p = philo->connect;
	i = 0;
	while (1)
	{
		philo_eat(philo);
//		philo->number_of_time_eat++;
//		printf("num_of_philo_ate %d\n", p->num_of_philo_ate);
		gettimeofday(&current_time, NULL);
		printf("%ld %d is sleeping\n", (current_time.tv_sec -
			p->start_time.tv_sec) * 1000 + (current_time.tv_usec -
			p->start_time.tv_usec) / 1000, philo->philo_index);
		usleep(p->time_to_sleep * 1000);
		if (philo[i].is_dead == 1)
		{
			printf("philo dead\n");
			break ;
		}
//		printf("num_of_philo_ate %d\n", p->num_of_philo_ate);
		if (p->num_of_philo_ate == p->number_of_phs)
		{
			printf("All philosophers ate, num of times eat %d\n",
				   p->num_of_philo_ate);
			break ;
		}
		i++;
	}
	return (NULL);
}

void	philo_eat(t_philo_args *philo)
{
	t_philo 		*p;
	struct timeval	current_time;

	p = philo->connect;
	pthread_mutex_lock(&(p->forks[philo->left_fork]));
	gettimeofday(&current_time, NULL);
	printf("%ld %d has taken a fork\n", (current_time.tv_sec -
		p->start_time.tv_sec) * 1000 +
		   (current_time.tv_usec - p->start_time.tv_usec) / 1000,
		   philo->philo_index);
	pthread_mutex_lock(&(p->forks[philo->right_fork]));
	gettimeofday(&current_time, NULL);
	printf("%ld %d has taken a fork\n", (current_time.tv_sec -
		p->start_time.tv_sec) * 1000 + (current_time.tv_usec -
		p->start_time.tv_usec) / 1000, philo->philo_index);
	gettimeofday(&(philo->time_last_meal), NULL);
	printf("%ld %d is eating\n", (philo->time_last_meal.tv_sec -
		p->start_time.tv_sec) * 1000 +
			(philo->time_last_meal.tv_usec - p->start_time.tv_usec) / 1000,
			philo->philo_index);
	usleep(p->time_to_eat * 1000);
	philo->number_of_time_eat++;
	pthread_mutex_unlock(&(p->forks[philo->right_fork]));
	pthread_mutex_unlock(&(p->forks[philo->left_fork]));

}

void	*waiter_vision(void *philo_args)
{
	t_philo_args	*philo;
	t_philo			*p;
	struct	timeval	current_time;
	int				i;
	int				philo_is_dead;
//	int				j;

	philo = (t_philo_args *)philo_args;
	p = philo[0].connect;
	philo_is_dead = 0;
	while (1)
	{
		i = -1;
		while (++i < p->number_of_phs)
		{
			gettimeofday(&current_time, NULL);
			if ((current_time.tv_sec - philo[i].time_last_meal.tv_sec) * 1000
				+ (current_time.tv_usec - philo[i].time_last_meal.tv_usec) / 1000
				> p->time_to_die)
			{
				philo[i].is_dead = 1;
				philo_is_dead = 1;
				printf("%ld %d died\n", (current_time.tv_sec -
				p->start_time.tv_sec) * 1000 + (current_time.tv_usec -
				p->start_time.tv_usec) / 1000, philo[i].philo_index);
//				j = -1;
//				while (++j < p->number_of_phs)
//					pthread_detach(philo[j].philo_thread);
				break ;
			}
			if (philo->number_of_time_eat == p->number_of_times_each_philosopher_must_eat)
			{
				printf("num_of_philo_ate %d\n", p->num_of_philo_ate);
				(p->num_of_philo_ate)++;
			}
		}
		if (philo_is_dead == 1)
			break ;
		if (p->num_of_philo_ate == p->number_of_phs)
		{
//			j = -1;
//			while (++j < p->number_of_phs)
//				pthread_detach(philo[j].philo_thread);
//			break ;
		}
	}
	return (NULL);
}
