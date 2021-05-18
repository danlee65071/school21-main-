/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:22:23 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/05 13:22:25 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	length_num(long long unsign_n, int sign)
{
	size_t	len;

	len = 0;
	if (unsign_n == 0)
		return (1);
	while (unsign_n != 0)
	{
		unsign_n /= 10;
		len++;
	}
	if (sign == -1)
		len++;
	return (len);
}

static void	prepare_to_itoa(unsigned int n, long long *unsign_n, int *sign)
{
	if (n < 0)
	{
		*unsign_n = (-1) * (long long)n;
		*sign = -1;
	}
	else
	{
		*unsign_n = n;
		*sign = 1;
	}
}

char	*itoa_u(unsigned int n)
{
	size_t		len_n;
	long long	unsign_n;
	int			sign;
	char		*s;

	unsign_n = 0;
	sign = 0;
	prepare_to_itoa(n, &unsign_n, &sign);
	len_n = length_num(unsign_n, sign);
	s = malloc(sizeof(char) * (len_n + 1));
	if (!s)
		return (NULL);
	s[len_n] = '\0';
	len_n--;
	while (unsign_n != 0)
	{
		s[len_n] = unsign_n % 10 + '0';
		len_n--;
		unsign_n /= 10;
	}
	if (sign == -1)
		s[0] = '-';
	if (n == 0)
		s[0] = '0';
	return (s);
}
