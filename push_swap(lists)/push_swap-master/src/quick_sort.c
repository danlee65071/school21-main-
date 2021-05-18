/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:54:15 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 01:30:36 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_info(t_ps *all)
{
	all->status.moving = 1;
	all->status.mid = 0;
	all->status.max = all->max;
	all->status.next = 1;
	all->status.last = all->status.max + 1;
}

void	ft_first_search_mid_and_split(t_ps *all)
{
	int		mid;
	int		counter;

	all->status.mid = all->status.max / 2 + all->status.next;
	mid = all->status.mid;
	counter = all->status.max + 1;
	while (counter-- > 0)
	{
		if (all->head_a->num_index <= mid)
			pb(all);
		else
			ra(all);
	}
	all->status.moving++;
}

void	ft_search_mid_and_split_b(t_ps *all)
{
	int		mid;
	int		counter;

	all->status.max = all->status.mid;
	all->status.mid = (all->status.max - all->status.next) / 2 \
											+ all->status.next;
	mid = all->status.mid;
	counter = all->status.max - all->status.next + 1;
	while (counter-- > 0)
	{
		if (all->head_b->num_index == all->status.next)
		{
			pa(all);
			ra(all);
			all->status.next++;
		}
		else if (all->head_b->num_index > mid)
		{
			all->head_b->moving = all->status.moving;
			pa(all);
		}
		else
			rb(all);
	}
	all->status.moving++;
}

void	ft_search_mid_and_split_a(t_ps *all)
{
	int		flag;

	flag = all->head_a->moving;
	while (all->head_a->moving == flag && \
				all->head_a->num_index >= all->status.next)
	{
		if (all->head_a->num_index == all->status.next)
		{
			ra(all);
			all->status.next++;
		}
		else
		{
			if (all->head_a->num_index > all->status.mid)
				all->status.mid = all->head_a->num_index;
			pb(all);
		}
	}
}
