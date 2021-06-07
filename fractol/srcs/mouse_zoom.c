/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 21:16:52 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/05 21:16:54 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_zoom(int button, int x, int y, t_scene *scene)
{
	printf("button = %d\n", button);
	if (button == 1 || button == 4)
	{
//		mlx_mouse_get_pos(scene->window, &x, &y);
		if (button == 1)
			scene->scale *= 0.125;
		else
			scene->scale *= 1.2;
		printf("x = %d\ny = %d\n", x ,y);
		scene->view.x = x - scene->width / 2;
		scene->view.y = scene->height / 2 - y;
		fractol_Julia(scene);
		mlx_put_image_to_window(scene->mlx, scene->window, scene->img.img, 0,
								0);
		printf("x = %d\ny = %d\n", scene->view.x, scene->view.y);
	}
	return (0);
}
