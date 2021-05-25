/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:06:58 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/25 01:07:00 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	raytracing(void *mlx, void *window, t_scene *scene)
{
	int			mlx_x;
	int			mlx_y;
	float		x_angle;
	float		y_angle;
	float		y_ray;
	float		x_ray;
	int			color;
	t_vector	*ray;
	t_vplane	*vplane;

	mlx_x = 0;
	mlx_y = 0;
	vplane = get_view_plane(scene->width, scene->hight, scene->cameras->fov);
	y_angle = scene->hight / 2;
	while (y_angle >= (scene->hight / 2) * (-1))
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (scene->width / 2) * (-1);
		while (x_angle <= scene->width / 2)
		{
			x_ray = x_angle * vplane->x_pixel;
			ray - new_vector(x_ray)
		}
	}
}
