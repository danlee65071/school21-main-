/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:40:31 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/24 14:40:34 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

typedef struct	s_sphere
{
	t_vector	*center;
	float		radius;
}	t_sphere;

t_sphere	*new_sphere(t_vector *center, float radius);

#endif
