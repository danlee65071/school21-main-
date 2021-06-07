/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:13:11 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/04 15:13:12 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
	t_scene	scene;

	(void)argc;
	(void)argv;

	scene.mlx = mlx_init();
	scene.width = 200;
	scene.hight = 200;
	scene.view.x = 0;
	scene.view.y = 0;
	scene.scale = 2;
	scene.window = mlx_new_window(scene.mlx, scene.width, scene.hight,
							   "fractol");
	scene.img.img = mlx_new_image(scene.mlx, 1920, 1080);
	scene.img.addr = mlx_get_data_addr(scene.img.img, &scene.img.bits_per_pixel,
									&scene.img.line_length,&scene.img.endian);
	mlx_key_hook(scene.window, esc_close, &scene);
	mlx_mouse_hook(scene.window, mouse_zoom, &scene);
	mlx_hook(scene.window, 17, 0, x_close, &scene);
	fractol_Julia(&scene);
	mlx_put_image_to_window(scene.mlx, scene.window, scene.img.img, 0, 0);
	mlx_loop(scene.mlx);
	return (0);
}
