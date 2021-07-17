/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:40:30 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/15 17:40:32 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	philo_life_sem(t_data *data, t_philo *philo)
{
	philo_eat_bonus(data, philo);
	if (data->num_of_times_each_philo_must_eat != -1
		&& philo->num_of_times_eat >= data->num_of_times_each_philo_must_eat)
		return (1);
	sem_wait(data->sem_writing);
	printf("%ld %d is sleeping\n", calculating_time_bonus(data->start_time),
		   philo->philo_index);
	sem_post(data->sem_writing);
	philo_time_sleep_bonus(data->start_time, data->time_to_sleep);
	sem_wait(data->sem_writing);
	printf("%ld %d is thinking\n", calculating_time_bonus(data->start_time),
		   philo->philo_index);
	sem_post(data->sem_writing);
	return (0);
}

static long	to_int_bonus(const char *str, size_t i, int sign)
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

int	ft_atoi_bonus(const char *str)
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
	res = to_int_bonus(str, i, sign);
	return ((int)res);
}

long	calculating_time_bonus(struct timeval time)
{
	struct timeval	current_time;
	long			time_in_ms;

	gettimeofday(&current_time, NULL);
	time_in_ms = (current_time.tv_sec - time.tv_sec) * 1000
		+ (current_time.tv_usec - time.tv_usec) / 1000;
	return (time_in_ms);
}

void	philo_time_sleep_bonus(struct timeval start_time, int time_sleep)
{
	long	till_time;

	till_time = calculating_time_bonus(start_time) + time_sleep;
	while (calculating_time_bonus(start_time) < till_time)
		usleep(100);
}
