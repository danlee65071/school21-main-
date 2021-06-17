/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_Julia.fract.c                                    :+:      :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 01:07:44 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/12 01:07:46 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_fract_julia
{
	t_complex	z;
	t_complex	c;
	float		radius;
	int			x;
	int			y;
	int			n;
}	t_fract_julia;

static int	fract_func_julia(t_fract_julia fract)
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

void	fractol_Julia(t_scene *scene)
{
	t_fract_julia	fract;

	fract.c = complex_init(-1, 0);
	fract.radius = (1 + sqrtf(1 + 4 * complex_abs(fract.c))) / 2;
	fract.x = -1;
	while (++fract.x < scene->width)
	{
		fract.y = -1;
		while (++fract.y < scene->height)
		{
			fract.z = complex_init(((float)fract.x - scene->O1.x) / ((float)
						scene->width / (2 * fract.radius) * scene->scale),
					(scene->O1.y - (float)fract.y) / ((float)
						scene->height / (2 * fract.radius) * scene->scale));
			fract.n = fract_func_julia(fract);
			if (fract.n != MAXITER)
				my_mlx_pixel_put(scene, fract.x, fract.y, GREEN + (float)
					fract.n / (MAXITER - 1) * (YELLOW - GREEN));
			else
				my_mlx_pixel_put(scene, fract.x, fract.y, BLACK);
		}
	}
}
