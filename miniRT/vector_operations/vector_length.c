/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:16:26 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/24 14:16:27 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float	vector_length(t_vector *vector)
{
	float	length;

	length = 0;
	length = sqrt(pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2));
	return (length);
}
