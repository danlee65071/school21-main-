/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_view_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:24:11 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/25 11:24:13 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vplane	*get_view_plane(float width, float hight, float fov)
{
	t_vplane	*vplane;
	float		aspect_ratio;

	vplane = malloc(sizeof(vplane));
	if (!vplane)
		error_call(-1);
	aspect_ratio = width / hight;
	vplane->width = 2 * tan(fov / 2 * (M_PI /  180));
	vplane->hight = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->hight / hight;
	return (vplane);
}
