/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:40:44 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/04 23:40:46 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	parse_flags(char *format, size_t i, t_flags *flags, va_list arguments)
{
	while (format[i])
	{
		if (format[i] == '0' && !(flags->width) && !(flags->minus))
			flags->zero = 1;
		else if (format[i] == '.')
			flag_dot(format, &i, flags, arguments);
		else if (format[i] == '-')
			flag_minus(flags);
		else if (format[i] == '*')
			flag_width(arguments, flags);
		else if (ft_isdigit(format[i]))
			flag_digit(format[i], flags);
		else if (is_type(format[i]))
		{
			flags->type = format[i];
			break ;
		}
		i++;
	}
	return (i);
}
