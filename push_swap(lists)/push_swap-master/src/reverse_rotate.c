/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:56:36 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 16:38:05 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ps *all)
{
	t_stack	*p1;
	t_stack	*p2;

	p1 = NULL;
	p2 = NULL;
	if ((all->head_a && all->tail_a) && all->size_a > 2)
	{
		p1 = all->tail_a;
		p2 = all->tail_a->prev;
		p1->prev = NULL;
		all->head_a->prev = p1;
		p1->next = all->head_a;
		p2->next = NULL;
		all->tail_a = p2;
		all->head_a = p1;
		if (all->checker_on == 0)
			write(1, "rra\n", 4);
	}
	else if (all->size_a <= 2)
		sa(all);
}

void	rrb(t_ps *all)
{
	t_stack	*p1;
	t_stack	*p2;

	p1 = NULL;
	p2 = NULL;
	if ((all->head_b && all->tail_b) && all->size_b > 2)
	{
		p1 = all->tail_b;
		p2 = all->tail_b->prev;
		p1->prev = NULL;
		all->head_b->prev = p1;
		p1->next = all->head_b;
		p2->next = NULL;
		all->tail_b = p2;
		all->head_b = p1;
		if (all->checker_on == 0)
			write(1, "rrb\n", 4);
	}
	else if (all->size_b <= 2)
		sb(all);
}

int		rra_rrr(t_ps *all)
{
	t_stack	*p1;
	t_stack	*p2;

	p1 = NULL;
	p2 = NULL;
	if ((all->head_a && all->tail_a) && all->size_a > 2)
	{
		p1 = all->tail_a;
		p2 = all->tail_a->prev;
		p1->prev = NULL;
		all->head_a->prev = p1;
		p1->next = all->head_a;
		p2->next = NULL;
		all->tail_a = p2;
		all->head_a = p1;
		return (1);
	}
	return (0);
}

int		rrb_rrr(t_ps *all)
{
	t_stack	*p1;
	t_stack	*p2;

	p1 = NULL;
	p2 = NULL;
	if ((all->head_b && all->tail_b) && all->size_b > 2)
	{
		p1 = all->tail_b;
		p2 = all->tail_b->prev;
		p1->prev = NULL;
		all->head_b->prev = p1;
		p1->next = all->head_b;
		p2->next = NULL;
		all->tail_b = p2;
		all->head_b = p1;
		return (1);
	}
	return (0);
}
