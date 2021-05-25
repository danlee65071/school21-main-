/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dot_product.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:30:31 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/24 14:30:33 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float	vector_dot_product(t_vector *vector1, t_vector *vector2)
{
	float	dot_product;

	dot_product = vector1->x * vector2->x + vector1->y * vector2->y
			+ vector1->z * vector2->z;
	return (dot_product);
}
