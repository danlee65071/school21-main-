/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:54:02 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/24 13:54:03 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

t_vector	*new_vector(float x, float y, float z);
t_vector	*vector_subtraction(t_vector *vector1, t_vector *vector2);
float		vector_length(t_vector *vector);
void		vector_normalize(t_vector *vector);
float		vector_dot_product(t_vector *vector1, t_vector *vector2);

#endif
