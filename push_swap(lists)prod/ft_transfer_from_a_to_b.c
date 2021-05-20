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

static void	ft_to_top(t_stacks **stack_a, t_stacks *start_stack_a,
					  t_stacks *end_stack_a, int median)
{
	if (start_stack_a->value <= median)
		ft_to_top_in_stack(stack_a, start_stack_a->value, 1);
	else if (start_stack_a->next->value <= median
		&& start_stack_a->next->value < end_stack_a->value)
		ft_to_top_in_stack(stack_a, start_stack_a->next->value, 1);
	else
		ft_to_top_in_stack(stack_a, end_stack_a->value, 1);
}

static void	ft_after_to_top(t_stacks **stack_a, t_stacks **stack_b,
							t_stacks **start_stack_a, t_stacks **end_stack_a)
{
	ft_pb(stack_a, stack_b);
	*start_stack_a = *stack_a;
	*end_stack_a = ft_lstlast(*stack_a);
}

static void	ft_init_median_start_end(t_stacks **stack_a, int *median,
									 t_stacks **start_stack_a,
									 t_stacks **end_stack_a)
{
	*median = ft_find_median(*stack_a);
	*start_stack_a = *stack_a;
	*end_stack_a = ft_lstlast(*stack_a);
}

static void	ft_after_while(t_stacks **stack_a, t_stacks **stack_b,
						   t_stacks *start_stack_a, int median)
{
	if (start_stack_a && start_stack_a->value <= median)
	{
		ft_to_top_in_stack(stack_a, start_stack_a->value, 1);
		ft_pb(stack_a, stack_b);
	}
}

void	ft_transfer_from_a_to_b(t_stacks **stack_a, t_stacks **stack_b)
{
	int			median;
	t_stacks	*start_stack_a;
	t_stacks	*end_stack_a;

	if (ft_lstsize(*stack_a) == 3 || ft_lstsize(*stack_a) == 2)
		ft_sort_two_or_three(stack_a, stack_b, ft_lstsize(*stack_a));
	if (ft_lstsize(*stack_a) == 3 || ft_lstsize(*stack_a) == 2)
		return ;
	ft_init_median_start_end(stack_a, &median, &start_stack_a, &end_stack_a);
	while (start_stack_a != end_stack_a)
	{
		if (ft_lstsize(*stack_a) == 3)
			ft_sort_three(stack_a, stack_b);
		if (ft_lstsize(*stack_a) == 3)
			return ;
		if (start_stack_a->value <= median || end_stack_a->value <= median)
		{
			ft_to_top(stack_a, start_stack_a, end_stack_a, median);
			ft_after_to_top(stack_a, stack_b, &start_stack_a, &end_stack_a);
			continue ;
		}
		start_stack_a = start_stack_a->next;
		end_stack_a = end_stack_a->prev;
	}
	ft_after_while(stack_a, stack_b, start_stack_a, median);
}
