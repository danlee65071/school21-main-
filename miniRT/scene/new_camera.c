/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:52:31 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/24 22:52:32 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_camera	*new_camera(t_vector *position, t_vector *direction, float fov)
{
	t_camera	*new_camera;

	new_camera = malloc(sizeof(t_camera));
	if (!new_camera)
		error_call(-1);
	new_camera->position = position;
	new_camera->direction = direction;
	new_camera->fov = fov;
	return (new_camera);
}
