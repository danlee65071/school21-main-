/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_two_and_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:07:57 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/19 01:08:00 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_three_part_one(t_stacks **stack_a, t_stacks **stack_b)
{
	if ((*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		if (*stack_b && ft_lstsize(*stack_b) > 2
			&& (*stack_b)->value < (*stack_b)->next->value)
			ft_ss(stack_a, stack_b);
		else
			ft_sa(stack_a, 0);
		if (*stack_b && ft_lstsize(*stack_b) > 2
			&& ft_lstlast(*stack_b)->value > (*stack_b)->value)
			ft_rrr(stack_a, stack_b);
		else
			ft_rra(stack_a, 0);
	}
	else
	{
		if (*stack_b && ft_lstsize(*stack_b) > 2
			&& (*stack_b)->value < ft_lstlast(*stack_b)->value)
			ft_rr(stack_a, stack_b);
		else
			ft_ra(stack_a, 0);
	}
}

static void	ft_sort_three_part_two(t_stacks **stack_a, t_stacks **stack_b)
{
	if (*stack_b && ft_lstsize(*stack_b) > 2
		&& (*stack_b)->value < (*stack_b)->next->value)
		ft_ss(stack_a, stack_b);
	else
		ft_sa(stack_a, 0);
	if (*stack_b && ft_lstsize(*stack_b) > 2
		&& (*stack_b)->value < ft_lstlast(*stack_b)->value)
		ft_rr(stack_a, stack_b);
	else
		ft_ra(stack_a, 0);
}

void	ft_sort_two(t_stacks **stack_a, t_stacks **stack_b)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		if (*stack_b && ft_lstsize(*stack_b) > 2
			&& (*stack_b)->value < ft_lstlast(*stack_b)->value)
			ft_rr(stack_a, stack_b);
		else
			ft_ra(stack_a, 0);
	}
}

void	ft_sort_three(t_stacks **stack_a, t_stacks **stack_b)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		if ((*stack_a)->value < (*stack_a)->next->next->value)
		{
			if (*stack_b && ft_lstsize(*stack_b) > 2
				&& (*stack_b)->value < (*stack_b)->next->value)
				ft_ss(stack_a, stack_b);
			else
				ft_sa(stack_a, 0);
		}
		else
			ft_sort_three_part_one(stack_a, stack_b);
	}
	else
	{
		if ((*stack_a)->value < (*stack_a)->next->next->value)
			ft_sort_three_part_two(stack_a, stack_b);
		if (*stack_b && ft_lstsize(*stack_b) > 2
			&& ft_lstlast(*stack_b)->value > (*stack_b)->value)
			ft_rrr(stack_a, stack_b);
		else
			ft_rra(stack_a, 0);
	}
}

void	ft_sort_two_or_three(t_stacks **stack_a, t_stacks **stack_b, int
								quantity_els)
{
	if (quantity_els == 3)
		ft_sort_three(stack_a, stack_b);
	else if (quantity_els == 2)
		ft_sort_two(stack_a, stack_b);
}
