/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 21:17:35 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/11 21:17:36 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	start(t_scene scene)
{
	scene.width = 600;
	scene.height = 600;
	scene.O1.x = (float)scene.width / 2;
	scene.O1.y = (float)scene.height / 2;
	scene.scale = 1;
	scene.mlx = mlx_init();
	scene.window = mlx_new_window(scene.mlx, scene.width, scene.height,
			"fractol");
	scene.img = mlx_new_image(scene.mlx, scene.width, scene.height);
	scene.addr = mlx_get_data_addr(scene.img, &scene.bits_per_pixel,
			&scene.line_length, &scene.endian);
	get_fractol(&scene);
	mlx_put_image_to_window(scene.mlx, scene.window, scene.img, 0, 0);
	mlx_hook(scene.window, 17, 0, x_close, &scene);
	mlx_hook(scene.window, 2, 0, keyboard, &scene);
	mlx_mouse_hook(scene.window, mouse_zoom, &scene);
	mlx_loop(scene.mlx);
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (parse(argc, argv, &scene) == 1)
		start(scene);
	else
		ft_putstr_fd("The list of available parameters: [\"Julia\", "
			   "\"Mandelbrot\", \"BurningShip\"]\nUse: ./fractol [parameter]\n",
			   2);
	return (0);
}
