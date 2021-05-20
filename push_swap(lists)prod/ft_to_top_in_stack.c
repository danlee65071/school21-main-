/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_top_in_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:48:10 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/17 09:48:12 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_stack_rotation(t_stacks **stack, int value_to_top, int
								is_stack_a, int is_r)
{
	while ((*stack)->value != value_to_top)
	{
		if (is_stack_a)
		{
			if (is_r)
				ft_ra(stack, 0);
			else
				ft_rra(stack, 0);
		}
		else
		{
			if (is_r)
				ft_rb(stack, 0);
			else
				ft_rrb(stack, 0);
		}
	}
}

void	ft_to_top_in_stack(t_stacks **stack, int value_to_top, int is_stack_a)
{
	int	mid;
	int	place_value_to_top;

	mid = ft_lstsize(*stack) / 2;
	place_value_to_top = ft_find_place_value(*stack, value_to_top);
	if (!place_value_to_top)
		return ;
	else if (place_value_to_top <= mid)
		ft_stack_rotation(stack, value_to_top, is_stack_a, 1);
	else
		ft_stack_rotation(stack, value_to_top, is_stack_a, 0);
}
