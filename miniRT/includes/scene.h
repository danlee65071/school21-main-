/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:58:07 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/24 22:58:08 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct	s_scene
{
	t_camera	*cameras;
	t_sphere	*sphere;
	float		width;
	float		hight;
}	t_scene;

t_scene	*new_scene(t_camera *camera, t_sphere *sphere);

#endif
