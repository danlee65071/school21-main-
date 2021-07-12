/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:34:39 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/08 18:34:40 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	to_int(const char *str, size_t i, int sign);

int	philos_forks_init(t_philo *philo)
{
	int	i;

	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->number_of_phs);
	if (philo->forks == NULL)
	{
		printf("Forks malloc error!\n");
		return (1);
	}
	i = -1;
	while (++i < philo->number_of_phs)
		if (pthread_mutex_init(&(philo->forks[i]), NULL) != 0)
			return (1);
	return (0);
}

int	philo_init(t_philo_args **philo_args, t_philo *connect)
{
	int	i;

	i = -1;
	*philo_args = malloc(sizeof(t_philo_args) * connect->number_of_phs);
	if (*philo_args == NULL)
	{
		printf("Philosophers init error!\n");
		return (1);
	}
	while (++i < connect->number_of_phs)
		(*philo_args)[i].connect = connect;
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
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	res;
	size_t	i;
	int		sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		   || str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	res = to_int(str, i, sign);
	return ((int)res);
}

static long	to_int(const char *str, size_t i, int sign)
{
	int	rank;
	int	res;

	res = 0;
	rank = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (rank > 11 && sign == 1)
			return (-1);
		else if (rank > 11 && sign == -1)
			return (0);
		res = res * 10 + str[i] - '0';
		rank++;
		i++;
	}
	res *= sign;
	return (res);
}
