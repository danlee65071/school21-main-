/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:51:56 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/05 11:51:59 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	proc_pointer_minus(t_flags flags, char *str)
{
	size_t	len;

	len = 0;
	len += put_str_with_precision("0x", 2);
	if (flags.precision >= 0)
	{
		len += add_width(flags.precision - 1, ft_strlen(str), 0);
		len += put_str_with_precision(str, flags.precision);
	}
	else
		len += put_str_with_precision(str, ft_strlen(str));
	return (len);
}

static char	*proc_str_pointer(unsigned long n)
{
	size_t			counter;
	char			*str;
	unsigned long	tmp;

	counter = 0;
	tmp = n;
	while (tmp != 0)
	{
		tmp /= 16;
		counter++;
	}
	str = malloc(sizeof (char) * (counter + 1));
	str[counter] = '\0';
	counter--;
	while (n != 0)
	{
		if ((n % 16) < 10)
			str[counter] = n % 16 + '0';
		else
			str[counter] = n % 16 + 87;
		n /= 16;
		counter--;
	}
	return (str);
}

size_t	proc_pointer(unsigned long n, t_flags flags)
{
	char	*str;
	size_t	len;

	len = 0;
	if (n == 0 && flags.precision == 0)
	{
		len += put_str_with_precision("0x", 2);
		len += add_width(flags.width, 0, 1);
		return (len);
	}
	if (n == 0)
	{
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
	}
	else
		str = proc_str_pointer(n);
	if (flags.minus == 1)
		len += proc_pointer_minus(flags, str);
	len += add_width(flags.width, ft_strlen(str) + 2, 0);
	if (flags.minus == 0)
		len += proc_pointer_minus(flags, str);
	free(str);
	return (len);
}
