/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:25:01 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 16:39:26 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *all)
{
	t_stack	*p1;
	t_stack	*p2;
	t_stack	*p3;

	p1 = NULL;
	p2 = NULL;
	p3 = NULL;
	if (all->head_a && all->head_a->next && all->size_a > 2)
	{
		p1 = all->head_a;
		p2 = all->head_a->next;
		p2->prev = NULL;
		p3 = all->tail_a;
		p3->next = p1;
		all->head_a = p2;
		all->head_a->next = p2->next;
		p3->prev = all->tail_a->prev;
		p1->prev = p3;
		p1->next = NULL;
		all->tail_a = p1;
		if (all->checker_on == 0)
			write(1, "ra\n", 3);
	}
	else if (all->size_a <= 2)
		sa(all);
}

void	rb(t_ps *all)
{
	t_stack	*p1;
	t_stack	*p2;
	t_stack	*p3;

	p1 = NULL;
	p2 = NULL;
	p3 = NULL;
	if (all->head_b && all->head_b->next && all->size_b > 2)
	{
		p1 = all->head_b;
		p2 = all->head_b->next;
		p2->prev = NULL;
		p3 = all->tail_b;
		p3->next = p1;
		all->head_b = p2;
		all->head_b->next = p2->next;
		p3->prev = all->tail_b->prev;
		p1->prev = p3;
		p1->next = NULL;
		all->tail_b = p1;
		if (all->checker_on == 0)
			write(1, "rb\n", 3);
	}
	else if (all->size_b <= 2)
		sb(all);
}

int		ra_rr(t_ps *all)
{
	t_stack	*p1;
	t_stack	*p2;
	t_stack	*p3;

	p1 = NULL;
	p2 = NULL;
	p3 = NULL;
	if (all->head_a && all->head_a->next && all->size_a > 2)
	{
		p1 = all->head_a;
		p2 = all->head_a->next;
		p2->prev = NULL;
		p3 = all->tail_a;
		p3->next = p1;
		all->head_a = p2;
		all->head_a->next = p2->next;
		p3->prev = all->tail_a->prev;
		p1->prev = p3;
		p1->next = NULL;
		all->tail_a = p1;
		return (1);
	}
	return (0);
}

int		rb_rr(t_ps *all)
{
	t_stack	*p1;
	t_stack	*p2;
	t_stack	*p3;

	p1 = NULL;
	p2 = NULL;
	p3 = NULL;
	if (all->head_b && all->head_b->next && all->size_b > 2)
	{
		p1 = all->head_b;
		p2 = all->head_b->next;
		p2->prev = NULL;
		p3 = all->tail_b;
		p3->next = p1;
		all->head_b = p2;
		all->head_b->next = p2->next;
		p3->prev = all->tail_b->prev;
		p1->prev = p3;
		p1->next = NULL;
		all->tail_b = p1;
		return (1);
	}
	return (0);
}
