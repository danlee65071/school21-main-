/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:56:29 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/24 13:56:31 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	*new_vector(float x, float y, float z)
{
	t_vector	*new;

	new = malloc(sizeof(t_vector));
	if (!new)
		error_call(-1);
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}
