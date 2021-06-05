/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 17:59:27 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/05 17:59:28 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sqrt_complex(t_complex z)
{
	t_complex	sqrt_z;

	sqrt_z.re = z.re * z.re - z.im * z.im;
	sqrt_z.im = 2 * z.re * z.im;
	return (sqrt_z);
}
