/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:36:43 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/05 00:36:45 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_width(va_list arguments, t_flags *flags)
{
	flags->star = 1;
	flags->width = va_arg(arguments, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width = (-1) * flags->width;
		flags->zero = 0;
	}
}
