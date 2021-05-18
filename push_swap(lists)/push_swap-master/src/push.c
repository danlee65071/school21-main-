/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 19:16:43 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 01:29:10 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_data(t_stack *from, t_stack *to)
{
	to->num = from->num;
	to->num_index = from->num_index;
	to->moving = from->moving;
}

void	ps_clear_push(t_ps *all, t_stack *a, t_stack *b)
{
	t_stack	*p1;
	t_stack	*p2;

	if (a)
	{
		p1 = all->head_a;
		p2 = all->head_a->next;
		p2->prev = NULL;
		p2->next = all->head_a->next->next;
		all->head_a = p2;
		free(p1);
	}
	if (b)
	{
		p1 = all->head_b;
		p2 = all->head_b->next;
		p2->prev = NULL;
		p2->next = all->head_b->next->next;
		all->head_b = p2;
		free(p1);
	}
}

void	pb_case_1(t_ps *all)
{
	all->head_b = init_empty();
	copy_data(all->head_a, all->head_b);
	all->head_b->next = NULL;
	ps_clear_push(all, all->a, NULL);
	all->b = all->head_b;
	all->tail_b = all->head_b;
	all->size_b++;
	all->size_a--;
}

void	pb(t_ps *all)
{
	if (all->head_b == NULL && all->head_a != NULL)
		pb_case_1(all);
	else if (all->head_b != NULL && all->head_a != NULL \
							&& all->head_a->next == NULL)
		pb_case_2(all);
	else if (all->head_b != NULL && all->head_a != NULL)
		pb_case_3(all);
	if (all->checker_on == 0)
		write(1, "pb\n", 3);
}

void	pa(t_ps *all)
{
	if (all->head_a == NULL && all->head_b != NULL)
		pa_case_1(all);
	else if (all->head_a != NULL && all->head_b != NULL \
							&& all->head_b->next == NULL)
		pa_case_2(all);
	else if (all->head_a != NULL && all->head_b != NULL)
		pa_case_3(all);
	if (all->checker_on == 0)
		write(1, "pa\n", 3);
}
