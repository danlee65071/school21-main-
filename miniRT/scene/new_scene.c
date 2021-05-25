/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:00:54 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/24 23:00:57 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_scene	*new_scene(t_camera *camera, t_sphere *sphere)
{
	t_scene	*new_scene;

	new_scene = malloc(sizeof(t_scene));
	if (!new_scene)
		error_call(-1);
	new_scene->cameras = camera;
	new_scene->sphere = sphere;
	new_scene->width = 0;
	new_scene->hight = 0;
	return (new_scene);
}
