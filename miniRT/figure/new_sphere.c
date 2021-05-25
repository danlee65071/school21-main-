/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:45:01 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/24 14:45:03 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_sphere	*new_sphere(t_vector *center, float radius)
{
	t_sphere	*new_sphere;

	new_sphere = malloc(sizeof(t_sphere));
	if (!new_sphere)
		error_call(-1);
	new_sphere->center = center;
	new_sphere->radius = radius;
	return (new_sphere);
}
