/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_with_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:19:32 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/05 11:19:35 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_str_with_precision(char *str, int precision)
{
	size_t	len;

	len = 0;
	while (str[len] && len < precision)
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}
