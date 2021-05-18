/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 00:54:03 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 01:31:25 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_case_1(t_ps *all, t_stack *p1, t_stack *p2, t_stack *p3)
{
	p1 = all->head_a;
	p2 = all->head_a->next;
	if (all->head_a->next->next)
	{
		p3 = all->head_a->next->next;
		p2->prev = NULL;
		p2->next = p1;
		p1->prev = p2;
		p1->next = p3;
		p3->prev = p1;
		all->head_a = p2;
		all->head_a->next = p1;
	}
	else
	{
		p2->prev = NULL;
		p2->next = p1;
		p1->prev = p2;
		p1->next = NULL;
		all->head_a = p2;
		all->head_a->next = p1;
		all->tail_a = p1;
		all->tail_a->prev = all->head_a;
	}
}

void	sb_case_1(t_ps *all, t_stack *p1, t_stack *p2, t_stack *p3)
{
	p1 = all->head_b;
	p2 = all->head_b->next;
	if (all->head_b->next->next)
	{
		p3 = all->head_b->next->next;
		p2->prev = NULL;
		p2->next = p1;
		p1->prev = p2;
		p1->next = p3;
		p3->prev = p1;
		all->head_b = p2;
		all->head_b->next = p1;
	}
	else
	{
		p2->prev = NULL;
		p2->next = p1;
		p1->prev = p2;
		p1->next = NULL;
		all->head_b = p2;
		all->head_b->next = p1;
		all->tail_b = p1;
		all->tail_b->prev = all->head_b;
	}
}
