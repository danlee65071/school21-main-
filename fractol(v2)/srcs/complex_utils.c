/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 01:14:47 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/12 01:14:49 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_init(float re, float im)
{
	t_complex	new_complex_num;

	new_complex_num.re = re;
	new_complex_num.im = im;
	return (new_complex_num);
}

float	complex_abs(t_complex complex_num)
{
	return (sqrtf(powf(complex_num.re, 2) + powf(complex_num.im, 2)));
}

void	complex_sqr(t_complex *complex_num)
{
	t_complex	tmp;

	tmp = *complex_num;
	complex_num->re = powf(tmp.re, 2) - powf(tmp.im, 2);
	complex_num->im = 2 * tmp.re * tmp.im;
}

t_complex	complex_sum(t_complex num1, t_complex num2)
{
	t_complex	result;

	result.re = num1.re + num2.re;
	result.im = num1.im + num2.im;
	return (result);
}
