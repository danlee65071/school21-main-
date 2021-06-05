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
	int 		transperency;
	int			red;
	int 		green;
	int 		blue;

	p_width = scene->width / 2;
	p_hight = scene->hight / 2;
	scale = p_hight / scene->scale;
	c = complex_init(-1, 0);
	r = init_radius(c);
	x = -p_width + scene->view.x;
	while (x < p_width + scene->view.x)
	{
		y = -p_hight + scene->view.x;
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
				transperency = (n % 4) * 16;
				red = (n % 2) * 32 + 128;
				green = (n % 4) * 64 + 32;
				blue = (n % 2) * 16 + 64;
				my_mlx_pixel_put(&scene->img, x + p_width - scene->view.x,
					 y + p_hight - scene->view.y,
								 create_trgb(transperency, red, green, blue));
			}
			y++;
		}
		x++;
	}
}
