/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_BurningShip.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:49:20 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/12 19:49:21 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_fractal_BS
{
	t_complex			z;
	int					x;
	int					y;
	int					n;
	float				z_tmp;
	float				z_re;
	float				z_im;
}	t_fractal_BS;

static int	fract_func_BS(t_fractal_BS fract)
{
	fract.n = -1;
	while (++fract.n < MAXITER)
	{
		fract.z_tmp = fract.z.re * fract.z.re - fract.z.im * fract.z
			.im + fract.z_re;
		fract.z.im = fabsf(2 * fract.z.re * fract.z.im) + fract.z_im;
		fract.z.re = fract.z_tmp;
		if (complex_abs(fract.z) > 4)
			break ;
	}
	return (fract.n);
}

void	fractol_BurningShip(t_scene *scene)
{
	t_fractal_BS	fract;

	fract.x = -1;
	while (++fract.x < scene->width)
	{
		fract.y = -1;
		while (++fract.y < scene->height)
		{
			fract.z_re = ((float)fract.x - scene->O1.x) / ((float)
					scene->width / 4 * scene->scale);
			fract.z_im = -(scene->O1.y - (float)fract.y) / ((float)
					scene->height / 4 * scene->scale);
			fract.z = complex_init(fract.z_re, fract.z_im);
			fract.n = fract_func_BS(fract);
			if (fract.n != MAXITER)
				my_mlx_pixel_put(scene, fract.x, fract.y, GREEN + (float)
					fract.n / (MAXITER - 1) * (RED - GREEN));
			else
				my_mlx_pixel_put(scene, fract.x, fract.y, BLACK);
		}
	}
}
