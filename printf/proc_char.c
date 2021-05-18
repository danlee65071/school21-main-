/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:16:39 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/05 10:16:41 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	proc_char(char c, t_flags flags)
{
	size_t	len;

	len = 0;
	if (flags.minus == 1)
		write(1, &c, 1);
	len = add_width(flags.width, 1, 0);
	if (flags.minus == 0)
		write(1, &c, 1);
	len++;
	return (len);
}
