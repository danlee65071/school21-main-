/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 01:45:29 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/12 01:45:32 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_scene *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	x_close(t_scene *scene)
{
	mlx_destroy_window(scene->mlx, scene->window);
	exit (0);
}

void	get_fractol(t_scene *scene)
{
	if (ft_strcmp(scene->fractol_name, "Julia") == 1)
		fractol_Julia(scene);
	else if (ft_strcmp(scene->fractol_name, "Mandelbrot") == 1)
		fractol_Mandelbrot(scene);
	else if (ft_strcmp(scene->fractol_name, "BurningShip") == 1)
		fractol_BurningShip(scene);
}
