/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:35:50 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/05 18:35:52 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_sum(t_complex z1, t_complex z2)
{
	t_complex	res_z;

	res_z.re = z1.re + z2.re;
	res_z.im = z1.im + z2.im;
	return (res_z);
}
