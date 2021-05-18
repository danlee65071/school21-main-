/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   production.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:02:45 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 14:34:51 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*foo_stacks(int count, int *stack)
{
	t_ps	*all;
	int		i;

	i = 0;
	if (!(all = (t_ps *)malloc(sizeof(t_ps))))
		exit(EXIT_FAILURE);
	all->head_b = NULL;
	all->size_b = 0;
	all->total = count;
	fill_linked_list(all, stack);
	set_index(all->a, count, all);
	ft_fill_info(all);
	all->min = 0;
	return (all);
}

void	fill_linked_list(t_ps *all, int *stack)
{
	int	i;

	i = 0;
	while (i < all->total)
	{
		if (i == 0)
		{
			all->a = init(stack[i]);
			all->head_a = all->a;
			all->size_a = 1;
		}
		else
		{
			all->a = addelem(all->a, stack[i]);
			all->tail_a = all->a;
			all->size_a++;
		}
		i++;
	}
}

void	go_algo(t_ps *all)
{
	if (!check_if_sorted(all->head_a))
	{
		if (all->size_a == 2)
			sa(all);
		else if (all->size_a == 3)
			do_best_of_three_a(all);
		else if (all->size_a > 3 && all->size_a < 7)
			do_for_middle(all);
		else
		{
			ft_first_search_mid_and_split(all);
			while (all->status.next != all->status.last)
			{
				while (all->head_b)
					ft_search_mid_and_split_b(all);
				ft_search_mid_and_split_a(all);
			}
		}
	}
}

int		check_if_sorted(t_stack *stack)
{
	int		i;
	t_stack	*p;

	p = stack;
	i = p->num_index;
	while (p != NULL)
	{
		if (i == p->num_index)
		{
			i++;
			p = p->next;
		}
		else
			return (0);
	}
	return (1);
}

void	set_index(struct s_stack *stack, int count, t_ps *all)
{
	t_stack		*ret;
	int			index;

	index = 1;
	while ((ret = get_next_index(stack, count, all)))
		ret->num_index = index++;
	all->max = index - 1;
}
