/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 22:46:17 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/04 22:46:21 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	size_t	len;

	va_start(arguments, format);
	len = 0;
	len += parse_input((char *)format, arguments);
	va_end(arguments);
	return (len);
}
