/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:39:19 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 01:31:04 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_ps *all)
{
	if (all->head_a && all->head_a->next && all->head_b && all->head_b->next)
	{
		if (sa_ss(all) && sb_ss(all))
			if (all->checker_on == 0)
				write(1, "ss\n", 3);
	}
}

void	rr(t_ps *all)
{
	if (all->head_a && all->head_a->next && all->head_b && all->head_b->next)
	{
		if (all->size_a <= 2 && all->size_b <= 2)
			ss(all);
		else if (ra_rr(all) && rb_rr(all))
			if (all->checker_on == 0)
				write(1, "rr\n", 3);
	}
}

void	rrr(t_ps *all)
{
	if (all->head_b && all->tail_b && all->head_a && all->tail_a)
	{
		if (all->size_a <= 2 && all->size_b <= 2)
			ss(all);
		else if (rra_rrr(all) && rrb_rrr(all))
			if (all->checker_on == 0)
				write(1, "rrr\n", 4);
	}
}
