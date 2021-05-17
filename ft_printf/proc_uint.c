/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:02:13 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/05 13:02:15 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	proc_unit_minus(t_flags flags, char *str)
{
	size_t	len;

	len = 0;
	if (flags.precision >= 0)
		len += add_width(flags.width, ft_strlen(str), 1);
	len += put_str_with_precision(str, ft_strlen(s));
	return (len);
}

static size_t	proc_unit_tail(t_flags flags, char *str)
{
	size_t	len;

	len = 0;
	if (flags.minus == 1)
		len += proc_unit_minus(flags, str);
	if (flags.precision >= 0 && flags.precision <= ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		len += add_width(flags.width, 0, 0);
	}
	else
		len += add_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		if (flags.precision >= 0)
			len += add_width(flags.width, 0, 0);
		len += put_str_with_precision(str, ft_strlen(str));
	return (len);
}

size_t	proc_uint(unsigned int n, t_flags flags)
{
	char	*str;
	size_t	len;

	len = 0;
	n += 4294967295 + 1;
	if (flags.precision == 0 && n == 0)
		len += add_width(flags.width, 0, 0);
	else
	{
		str = itoa_u(n);
		len += proc_unit_tail(flags, str);
		free(str);
	}
	return (len);
}
