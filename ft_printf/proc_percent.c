/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:26:34 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/05 14:26:36 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	proc_percent(t_flags flags)
{
	size_t	len;

	len = 0;
	if (flags.minus == 1)
	{
		len += put_str_with_precision("%", 1);
		len += add_width(flags.width, 1, flags.zero);
	}
	else
		if (flags.minus == 0)
			len += put_str_with_precision("%", 1);
	return (len);
}
