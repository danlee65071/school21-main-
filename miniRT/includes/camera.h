/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:49:37 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/24 14:49:39 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct	s_camera
{
	t_vector	*position;
	t_vector	*direction;
	float		fov;
}	t_camera;

t_camera	*new_camera(t_vector *position, t_vector *direction, float fov);

#endif
