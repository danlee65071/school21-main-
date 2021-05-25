/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:19:45 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/25 16:19:46 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float	sphere_intersection(t_camera *camera, t_vector *ray, t_sphere *sphere)
{
	float		b;
	float		c;
	float		discrimenant;
	float		distance_1;
	float		distance_2;
	t_vector	*camera_sphere;

	distance_1 = 0;
	distance_2 = 0;
	camera_sphere = NULL;
	camera_sphere = vector_subtraction(camera->position, sphere->center);
	b = 2 * (vector_dot_product(camera_sphere, ray));
	c = vector_dot_product(camera_sphere, camera_sphere) - pow
			(sphere->radius, 2);
	discrimenant = pow(b, 2) - 4 * c;
	free(camera_sphere);
	distance_1 = ((-1) * b - sqrt(discrimenant)) / 2;
	distance_2 = ((-1) * b + sqrt(discrimenant)) / 2;
	if (distance_1 > 0)
		return (distance_1);
	else if (distance_2 > 0)
		return (distance_2);
	return (0);
}
