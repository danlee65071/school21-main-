/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:16:18 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/04 23:16:21 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	format_percent(char *format, va_list arguments, t_flags *flags,
							 size_t *i)
{
	size_t	len;

	len = 0;
	if (format[*i + 1] == ' ')
	{
		write(1, " ", 1);
		len++;
		(*i)++;
	}
	*i = parse_flags(format, ++(*i), flags, arguments);
	if (is_type(format[*i]))
		len += processor(format[*i], *flags, arguments);
	return (len);
}

int	parse_input(char *format, va_list arguments)
{
	t_flags	flags;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (1)
	{
		flags_init(&flags);
		if (format[i] == '\0')
			break ;
		if (format[i] == '%')
			len += format_percent(format, arguments, &flags, &i);
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}
