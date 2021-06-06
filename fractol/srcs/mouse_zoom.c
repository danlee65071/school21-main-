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
	if (button == 5)
	{
		mlx_mouse_get_pos(scene->window, &x, &y);
		scene->view.x = x - scene->width / 2;
		scene->view.y = y - scene->hight / 2;
		scene->scale *= 0.9;
		fractol_Julia(scene);
		mlx_put_image_to_window(scene->mlx, scene->window, scene->img.img, 0,
								0);
//		printf("x = %d\ny = %d\n", x, y);
	}
	else if (button == 4)
	{
		mlx_mouse_get_pos(scene->window, &x, &y);
		scene->view.x = x - scene->width / 2;
		scene->view.y = y - scene->hight / 2;
		scene->scale *= 1.1;
		fractol_Julia(scene);
		mlx_put_image_to_window(scene->mlx, scene->window, scene->img.img, 0,
								0);
	}
	return (0);
}
