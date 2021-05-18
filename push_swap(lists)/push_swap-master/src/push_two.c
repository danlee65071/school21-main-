/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 00:33:54 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 01:30:42 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_case_2(t_ps *all)
{
	t_stack *cache;

	cache = init_empty();
	copy_data(all->head_a, cache);
	cache->next = all->head_b;
	all->head_b->prev = cache;
	cache->prev = NULL;
	free(all->head_a);
	all->head_a = NULL;
	all->head_b = cache;
	all->b = all->head_b;
	all->size_b++;
	all->size_a--;
}

void	pb_case_3(t_ps *all)
{
	t_stack *cache;

	cache = init_empty();
	copy_data(all->head_a, cache);
	cache->next = all->head_b;
	all->head_b->prev = cache;
	cache->prev = NULL;
	ps_clear_push(all, all->a, NULL);
	all->head_b = cache;
	all->b = all->head_b;
	all->size_b++;
	all->size_a--;
	if (all->head_a->next == NULL)
		all->tail_a = all->head_a;
}

void	pa_case_1(t_ps *all)
{
	all->head_a = init_empty();
	copy_data(all->head_b, all->head_a);
	all->head_a->next = NULL;
	ps_clear_push(all, NULL, all->b);
	all->a = all->head_a;
	all->tail_a = all->head_a;
	all->size_a++;
	all->size_b--;
}

void	pa_case_2(t_ps *all)
{
	t_stack *cache;

	cache = init_empty();
	copy_data(all->head_b, cache);
	cache->next = all->head_a;
	all->head_a->prev = cache;
	cache->prev = NULL;
	free(all->head_b);
	all->head_b = NULL;
	all->head_a = cache;
	all->a = all->head_a;
	all->size_a++;
	all->size_b--;
}

void	pa_case_3(t_ps *all)
{
	t_stack *cache;

	cache = init_empty();
	copy_data(all->head_b, cache);
	cache->next = all->head_a;
	all->head_a->prev = cache;
	cache->prev = NULL;
	ps_clear_push(all, NULL, all->head_b);
	all->head_a = cache;
	all->a = all->head_a;
	all->size_a++;
	all->size_b--;
	if (all->head_b->next == NULL)
		all->tail_b = all->head_b;
}
