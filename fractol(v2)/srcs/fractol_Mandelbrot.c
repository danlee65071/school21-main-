/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_Mandelbrot.fract.c                               :+:      :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:45:55 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/12 15:45:56 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_fract_mand
{
	t_complex	z;
	t_complex	c;
	float		radius;
	int			x;
	int			y;
	int			n;
}	t_fract_mand;

static int	fract_func_mandelbrot(t_fract_mand fract)
{
	fract.n = -1;
	while (++fract.n < MAXITER)
	{
		complex_sqr(&fract.z);
		fract.z = complex_sum(fract.z, fract.c);
		if (complex_abs(fract.z) > fract.radius)
			break ;
	}
	return (fract.n);
}

void	fractol_Mandelbrot(t_scene *scene)
{
	t_fract_mand	fract;

	fract.x = -1;
	while (++fract.x < scene->width)
	{
		fract.y = -1;
		while (++fract.y < scene->height)
		{
			fract.c = complex_init(((float)fract.x - scene->O1.x) / ((float)
						scene->width / (2 * fract.radius) * scene->scale),
					(scene->O1.y - (float)fract.y) / ((float)
						scene->height / (2 * fract.radius) * scene->scale));
			fract.z = complex_init(0, 0);
			fract.radius = (1 + sqrtf(1 + 4 * complex_abs(fract.c))) / 2;
			fract.n = fract_func_mandelbrot(fract);
			if (fract.n != MAXITER)
				my_mlx_pixel_put(scene, fract.x, fract.y, GREEN + (float)
					fract.n / (MAXITER - 1) * (YELLOW - GREEN));
			else
				my_mlx_pixel_put(scene, fract.x, fract.y, BLACK);
		}
	}
}
