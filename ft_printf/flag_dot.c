/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_dot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:17:25 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/05 00:17:27 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_dot(char *format, size_t *i, t_flags *flags, va_list arguments)
{
	(*i)++
	if (format[*i] == '*')
	{
		flags->precision = va_arg(arguments, int );
		(*i)++;
	}
	else
	{
		flags->precision = 0;
		while (ft_isdigit(format[*i]))
		{
			flags->precision = flags->precision * 10 + format[*i] - '0';
			(*i)++;
		}
	}
}
