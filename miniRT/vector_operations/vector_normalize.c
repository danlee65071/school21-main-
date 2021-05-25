/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:20:57 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/24 14:20:58 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	vector_normalize(t_vector *vector)
{
	float	length;

	length = vector_length(vector);
	vector->x /= length;
	vector->y /= length;
	vector->z /= length;
}
