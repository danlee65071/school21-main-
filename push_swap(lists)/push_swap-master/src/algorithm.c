/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:15:26 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 18:40:27 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_best_of_three_a(t_ps *all)
{
	if (all->head_a->num_index < all->head_a->next->num_index)
	{
		if (all->head_a->num_index > all->head_a->next->next->num_index)
			rra(all);
		else
		{
			sa(all);
			ra(all);
		}
	}
	else
	{
		if (all->head_a->num_index > all->head_a->next->next->num_index)
		{
			if (all->head_a->next->num_index > all->tail_a->num_index)
			{
				sa(all);
				rra(all);
			}
			else
				ra(all);
		}
		else
			sa(all);
	}
}

void	do_best_of_three_b(t_ps *all)
{
	if (all->head_b->num_index < all->head_b->next->num_index)
	{
		if (all->head_b->num_index > all->head_b->next->next->num_index)
			rrb(all);
		else
		{
			sb(all);
			rb(all);
		}
	}
	else
	{
		if (all->head_b->num_index > all->head_b->next->next->num_index)
		{
			if (all->head_b->next->num_index > all->tail_b->num_index)
			{
				sb(all);
				rrb(all);
			}
			else
				rb(all);
		}
		else
			sb(all);
	}
}

void	do_for_middle(t_ps *all)
{
	while (all->size_a > 3)
	{
		if (all->head_a->num_index > 3)
			pb(all);
		else
			ra(all);
	}
	if (!check_if_sorted(all->head_a))
		do_best_of_three_a(all);
	if (!check_if_sorted(all->head_b))
	{
		if (all->size_b == 2)
			sb(all);
		else if (all->size_b == 3)
			do_best_of_three_b(all);
	}
	while (all->size_b != 0)
	{
		pa(all);
		ra(all);
	}
}
