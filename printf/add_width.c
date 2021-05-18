/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:11:21 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/05 11:11:22 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	add_width(int width, int minus, int is_zero)
{
	size_t	len;

	len = 0;
	while (width - minus > 0)
	{
		if (is_zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		len++;
		width--;
	}
	return (len);
}
