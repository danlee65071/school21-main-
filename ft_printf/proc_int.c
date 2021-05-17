/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:29:12 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/05 12:29:15 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	proc_int_minus(t_flags flags, int buf, char *str)
{
	size_t	len;

	len = 0;
	if (buf < 0 && flags.precision >= 0)
		write(1, "-", 1);
	if (flags.precision >= 0)
		len += add_width(flags.precision - 1, ft_strlen(str) - 1, 1);
	len += put_str_with_precision(str, ft_strlen(str));
	return (len);
}

static size_t	proc_int_tail(t_flags flags, char *str)
{
	size_t	len;

	len = 0;
	if (flags.precision >= 0 && flags.precision < ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		len += add_width(flags.width, 0, 0);
	}
	else
		len += add_width(flags.width, ft_strlen(str), 1);
	return (len);
}

size_t	proc_int(int n, t_flags flags)
{
	char	*str;
	int		buf;
	size_t	len;

	len = 0;
	buf = n;
	if (flags.precision == 0 && n == 0)
		len += add_width(flags.width, 0, 0);
	else
	{
		if (n < 0 && (flags.precision < 0 || flags.zero == 1))
		{
			if (flags.zero == 1 && flags.precision < 0 && n > -2147483648)
				len += put_str_with_precision("-", 1);
			if (n == -2147483648)
				len--;
			n *= -1;
			flags.zero = 1;
			flags.width -= 1;
			len++;
		}
		str = ft_itoa(n);
		if (flags.minus == 1)
			len += proc_int_minus(flags, buf, str);
		len += proc_int_tail(flags, str);
		if (flags.minus == 0)
			len += proc_int_minus(flags, buf, str);
		free(str);
	}
	return (len);
}
