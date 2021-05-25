/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_subtraction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:09:39 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/24 14:09:40 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	*vector_subtraction(t_vector *vector1, t_vector *vector2)
{
	t_vector	*result;

	result = new_vector(vector1->x - vector2->x, vector1->y - vector2->y,
					 vector1->z - vector2->z);
	return (result);
}
