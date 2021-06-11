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
	float		x;
	float 		y;
	t_center	center;
	t_complex	z;
	t_complex	c;
	int			n;
	float		r;
	t_color		color;

	c = complex_init(-1, 0);
	center.x = scene->view.x;
	center.y = scene->view.y;
	x = (center.x - scene->width - 1);
	while (++x < scene->width - center.x)
	{
		y = scene->height - center.y + 1;
		while (--y > center.y - scene->height)
		{
			z = complex_init(4 * x / scene->width, 4 * y / scene->height);
			n = -1;
			while (++n < MAXITER)
			{
				z = sqrt_complex(z);
				z = complex_sum(z, c);
				r = init_radius(z);
				if (abs_complex(z) > r)
					break ;
			}
			if (n != MAXITER)
			{
				color.b = ((float)n / r) * 100 + 128;
				color.g = ((float)n / (2 * r)) * 100 + 128;
				color.r = ((float)n / r) * 100 + 107;
			}
			else
			{
				color.r = 0;
				color.g = 0;
				color.b = 0;
			}
			my_mlx_pixel_put(&scene->img, x - center.x + scene->width,
							 scene->height - center.y - y,
							 create_trgb(0, color.r, color.g, color.b));
		}
	}
}

//void	fractol_Julia(t_scene *scene)
//{
//	t_complex	c;
//	t_complex	z;
//	int			p_width;
//	int			p_height;
//	int			x;
//	int			y;
//	int			n;
//	float		r;
//	int			red;
//	int 		green;
//	int 		blue;
//	t_center	center;
//
//	p_width = scene->width / 2;
//	p_height = scene->height / 2;
//	c = complex_init(-1, 0);
//	r = init_radius(c);
//	center.x = scene->view.x;
//	center.y = -scene->view.y;
//	x = (-p_width + center.x) / scene->scale;
//	while (x < (p_width + center.x) * scale)
//	{
//		y = (-p_height + center.y) * scale;
//		while (y < (p_height + center.y) * scale)
//		{
//			z = complex_init((float)x, (float)y);
//			n = -1;
//			while (++n < MAXITER)
//			{
//				z = sqrt_complex(z);
//				z = complex_sum(z, c);
//				if (abs_complex(z) > r)
//					break ;
//			}
//			if (n != MAXITER)
//			{
//				blue = ((float)n / r) * 100 + 128;
//				green = ((float)n / (2 * r)) * 100 + 128;
//				red = ((float)n / r) * 100 + 107;
//			}
//			else
//			{
//				red = 0;
//				green = 0;
//				blue = 0;
//			}
//			my_mlx_pixel_put(&scene->img, x + p_width,
//							 y + p_height,
//							 create_trgb(0, red, green, blue));
//			y++;
//		}
//		x++;
//	}
//}
