/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:41:51 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/12 13:41:53 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	esc_close(t_scene *scene)
{
	mlx_destroy_window(scene->mlx, scene->window);
	exit(0);
}

static int	fractol_move(int key, t_scene *scene)
{
	float	move_vertical;
	float	move_horizontal;

	move_vertical = scene->height / 20;
	move_horizontal = scene->width / 20;
	if (key == KEY_RIGHT)
		scene->O1.x -= move_horizontal;
	else if (key == KEY_LEFT)
		scene->O1.x += move_horizontal;
	else if (key == KEY_UP)
		scene->O1.y += move_vertical;
	else
		scene->O1.y -= move_vertical;
	get_fractol(scene);
	mlx_put_image_to_window(scene->mlx, scene->window, scene->img, 0, 0);
	mlx_do_sync(scene->mlx);
	return (0);
}

int	keyboard(int key, t_scene *scene)
{
	if (key == ESC_KEY)
		return (esc_close(scene));
	else if (key == KEY_UP || key == KEY_DOWN || key == KEY_RIGHT
		|| key == KEY_LEFT)
		return (fractol_move(key, scene));
	return (0);
}
