/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_plane.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:25:18 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/25 11:25:19 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_PLANE_H
# define VIEW_PLANE_H

typedef struct	s_vplane
{
	float	width;
	float	hight;
	float	x_pixel;
	float	y_pixel;
}	t_vplane;

t_vplane	*get_view_plane(float width, float hight, float fov);

#endif
