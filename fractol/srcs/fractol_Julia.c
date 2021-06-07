/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_Julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 17:19:00 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/05 17:19:01 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_Julia(t_scene *scene)
{
	t_complex	c;
	t_complex	z;
	int			p_width;
	int			p_hight;
	int			x;
	int			y;
	int			n;
	float		scale;
	float		r;
	int			red;
	int 		green;
	int 		blue;

	p_width = scene->width / 2;
	p_hight = scene->hight / 2;
	scale = (float)p_hight / scene->scale;
	c = complex_init(-1, 0);
	r = init_radius(c);
	x = -p_width + scene->view.x;
	while (x < p_width + scene->view.x)
	{
		y = -p_hight + scene->view.y;
		while (y < p_hight + scene->view.y)
		{
			z = complex_init((float)x / scale, (float)y / scale);
			n = -1;
			while (++n < MAXITER)
			{
				z = sqrt_complex(z);
				z = complex_sum(z, c);
				if (abs_complex(z) > r)
					break ;
			}
			if (n != MAXITER)
			{
				blue = ((float)n / r) * 100 + 128;
				green = ((float)n / (2 * r)) * 100 + 116;
				red = ((float)n / r) * 100 + 107;
			}
			else
			{
				red = 0;
				green = 0;
				blue = 0;
			}
			my_mlx_pixel_put(&scene->img, x + p_width - scene->view.x,
							 -(y - p_hight - scene->view.y),
							 create_trgb(0, red, green, blue));
			y++;
		}
		x++;
	}
}
