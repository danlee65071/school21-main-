/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:29:33 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/12 12:29:35 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_zoom(int button, int x, int y, t_scene *scene)
{
	mlx_mouse_get_pos(scene->window, &x, &y);
	if (button == MOUSE_ZOOM_UP || button == MOUSE_ZOOM_DOWN)
	{
		scene->arrow_local.x = (x - scene->O1.x) / scene->scale;
		scene->arrow_local.y = (scene->O1.y - y) / scene->scale;
		if (button == MOUSE_ZOOM_UP)
			scene->scale *= 1.2;
		else
			scene->scale /= 1.2;
		scene->O1.x = x - scene->arrow_local.x * scene->scale;
		scene->O1.y = y + scene->arrow_local.y * scene->scale;
		get_fractol(scene);
		mlx_put_image_to_window(scene->mlx, scene->window, scene->img, 0, 0);
		mlx_do_sync(scene->mlx);
	}
	return (0);
}
