/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfer_from_a_to_b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:13:34 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/17 00:13:38 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_transfer_from_a_to_b(t_stacks **stack_a, t_stacks **stack_b)
{
	int 		median;
	t_stacks	*start_stack_a;
	t_stacks	*end_stack_a;

	if (ft_lstsize(*stack_a) == 1)
	{
		ft_pb(stack_a, stack_b);
		return ;
	}
	median = ft_find_median(*stack_a);
	start_stack_a = *stack_a;
	end_stack_a = ft_lstlast(*stack_a);
	while (start_stack_a != end_stack_a)
	{
		if (start_stack_a->value <= median || end_stack_a->value <= median)
		{
			if (start_stack_a->value <= median)
				ft_to_top_in_stack(stack_a, start_stack_a->value, 1);
			else
				ft_to_top_in_stack(stack_a, end_stack_a->value, 1);
			ft_pb(stack_a, stack_b);
			start_stack_a = *stack_a;
			end_stack_a = ft_lstlast(*stack_a);
			continue ;
		}
		start_stack_a = start_stack_a->next;
		end_stack_a = end_stack_a->prev;
	}
}
