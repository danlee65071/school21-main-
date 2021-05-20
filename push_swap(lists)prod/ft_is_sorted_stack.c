/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:47:03 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/20 10:47:04 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted_stack(t_stacks *stack, int *sorted_arr)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value != sorted_arr[i])
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}
