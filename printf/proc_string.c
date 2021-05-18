/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:00:14 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/05 11:00:16 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	proc_string_minus(char *s, t_flags *flags)
{
	size_t	len;

	len = 0;
	if (flags->precision >= 0)
	{
		len += add_width(flags->precision, (int)ft_strlen(s), 0);
		len += put_str_with_precision(s, flags->precision);
	}
	else
		len += put_str_with_precision(s, (int)ft_strlen(s));
	return (len);
}

size_t	proc_string(char *s, t_flags *flags)
{
	size_t	len;

	len = 0;
	if (!s)
		s = "(null)";
	if (flags->precision >= 0 && flags->precision > (int)ft_strlen(s))
		flags->precision = (int)ft_strlen(s);
	if (flags->minus == 1)
		len += proc_string_minus(s, flags);
	if (flags->precision >= 0)
		len += add_width(flags->width, flags->precision, 0);
	else
		len += add_width(flags->width, (int)ft_strlen(s), 0);
	if (flags->minus == 0)
		len += proc_string_minus(s, flags);
	return (len);
}
