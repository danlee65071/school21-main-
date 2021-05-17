/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:08:53 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 20:08:55 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_place_value(t_stacks *stack, int value)
{
	int	place;

	place = 0;
	while (stack)
	{
		if (stack->value == value)
			return (place);
		place++;
		stack = stack->next;
	}
	return (0);
}
