/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfer_from_b_to_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:37:37 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/17 00:37:39 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_transfer_from_b_to_a(t_stacks **stack_a, t_stacks **stack_b, int
								*min_not_sorted_el, int *sorted_arr)
{
	int			median;
	t_stacks	*start_stack_b;
	t_stacks	*end_stack_b;

	if (ft_lstsize(*stack_b) == 1)
	{
		ft_pa(stack_a, stack_b);
		return ;
	}
	median = ft_find_median(*stack_b);
	start_stack_b = *stack_b;
	while (start_stack_b)
	{
		start_stack_b->was_in_b += 1;
		start_stack_b = start_stack_b->next;
	}
	start_stack_b = *stack_b;
	end_stack_b = ft_lstlast(*stack_b);
	while (start_stack_b != end_stack_b)
	{
		if (start_stack_b->value > median || end_stack_b->value > median)
		{
			if (start_stack_b->value > median)
				ft_to_top_in_stack(stack_b, start_stack_b->value, 0);
			else
				ft_to_top_in_stack(stack_b, end_stack_b->value, 0);
			ft_pa(stack_a, stack_b);
			ft_is_in_place(stack_a, min_not_sorted_el, sorted_arr);
			start_stack_b = *stack_b;
			end_stack_b = ft_lstlast(*stack_b);
			continue ;
		}
		start_stack_b = start_stack_b->next;
		end_stack_b = end_stack_b->prev;
	}
	if (start_stack_b == end_stack_b && start_stack_b)
	{
		if (start_stack_b->value > median)
			ft_to_top_in_stack(stack_b, start_stack_b->value, 0);
		ft_pa(stack_a, stack_b);
		ft_is_in_place(stack_a, min_not_sorted_el, sorted_arr);
	}
}

