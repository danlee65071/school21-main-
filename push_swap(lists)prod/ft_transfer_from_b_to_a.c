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

static void	ft_init_median_start_end(t_stacks **stack_b, int *median,
										   t_stacks **start_stack_b,
										   t_stacks **end_stack_b)
{
	*median = ft_find_median(*stack_b);
	*start_stack_b = *stack_b;
	while (*start_stack_b)
	{
		(*start_stack_b)->was_in_b += 1;
		(*start_stack_b) = (*start_stack_b)->next;
	}
	*start_stack_b = *stack_b;
	*end_stack_b = ft_lstlast(*stack_b);
}

static void	ft_to_top_in_b(t_stacks **stack_b, t_stacks *start_stack_b,
						   t_stacks *end_stack_b, int median)
{
	if (start_stack_b->value > median)
		ft_to_top_in_stack(stack_b, start_stack_b->value, 0);
	else
		ft_to_top_in_stack(stack_b, end_stack_b->value, 0);
}

static void	ft_set_start_end(t_stacks **stack_b, t_stacks **start_stack_b,
							 t_stacks **end_stack_b, int is_in_if)
{
	if (is_in_if)
	{
		*start_stack_b = *stack_b;
		*end_stack_b = ft_lstlast(*stack_b);
	}
	else
	{
		*start_stack_b = (*start_stack_b)->next;
		*end_stack_b = (*end_stack_b)->prev;
	}
}

static void	ft_after_while_in_if(t_stacks **stack_a, t_stacks **stack_b,
								 t_stacks *start_stack_b, int median)
{
	if (start_stack_b->value > median)
		ft_to_top_in_stack(stack_b, start_stack_b->value, 0);
	ft_pa(stack_a, stack_b);
}

void	ft_transfer_from_b_to_a(t_stacks **stack_a, t_stacks **stack_b, int
								*min_not_sorted_el, int *sorted_arr)
{
	int			median;
	t_stacks	*start_stack_b;
	t_stacks	*end_stack_b;

	if (ft_lstsize(*stack_b) == 1)
		ft_pa(stack_a, stack_b);
	if (ft_lstsize(*stack_b) == 0)
		return ;
	ft_init_median_start_end(stack_b, &median, &start_stack_b, &end_stack_b);
	while (start_stack_b != end_stack_b)
	{
		if (start_stack_b->value > median || end_stack_b->value > median)
		{
			ft_to_top_in_b(stack_b, start_stack_b, end_stack_b, median);
			ft_pa_and_is_in_pl(stack_a, stack_b, min_not_sorted_el, sorted_arr);
			ft_set_start_end(stack_b, &start_stack_b, &end_stack_b, 1);
			continue ;
		}
		ft_set_start_end(stack_b, &start_stack_b, &end_stack_b, 0);
	}
	if (start_stack_b == end_stack_b && start_stack_b)
	{
		ft_after_while_in_if(stack_a, stack_b, start_stack_b, median);
		ft_is_in_place(stack_a, min_not_sorted_el, sorted_arr);
	}
}
