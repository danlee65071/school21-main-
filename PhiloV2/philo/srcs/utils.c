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

long	calculating_time(struct timeval time)
{
	struct timeval	current_time;
	long			time_in_ms;

	gettimeofday(&current_time, NULL);
	time_in_ms = (current_time.tv_sec - time.tv_sec) * 1000
		+ (current_time.tv_usec - time.tv_usec) / 1000;
	return (time_in_ms);
}

void	philo_time_sleep(struct timeval start_time, int time_sleep)
{
	long	till_time;

	till_time = calculating_time(start_time) + time_sleep;
	while (calculating_time(start_time) < till_time)
		usleep(100);
}
