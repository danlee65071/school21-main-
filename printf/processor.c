/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:53:49 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/04 23:53:51 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	processor(char type, t_flags flags, va_list arguments)
{
	size_t	len;

	len = 0;
	if (type == 'c')
		len = proc_char(va_arg(arguments, int), flags);
	else if (type == 's')
		len = proc_string(va_arg(arguments, char *), &flags);
	else if (type == 'p')
		len = proc_pointer(va_arg(arguments, unsigned long), flags);
	else if (type == 'd' || type == 'i')
		len = proc_int(va_arg(arguments, int), flags);
	else if (type == 'u')
		len = proc_uint(va_arg(arguments, unsigned int), flags);
	else if (type == 'x')
		len = proc_hex(va_arg(arguments, unsigned int), 0, flags);
	else if (type == 'X')
		len = proc_hex(va_arg(arguments, unsigned int), 1, flags);
	else if (type == '%')
		len = proc_percent(flags);
	return (len);
}
