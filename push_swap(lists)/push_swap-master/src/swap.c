/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:28:20 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 01:31:21 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *all)
{
	t_stack *p1;
	t_stack *p2;
	t_stack	*p3;

	p1 = NULL;
	p2 = NULL;
	p3 = NULL;
	if (all->head_a && all->head_a->next)
		sa_case_1(all, p1, p2, p3);
	if (all->checker_on == 0)
		write(1, "sa\n", 3);
}

void	sb(t_ps *all)
{
	t_stack *p1;
	t_stack *p2;
	t_stack	*p3;

	p1 = NULL;
	p2 = NULL;
	p3 = NULL;
	if (all->head_b && all->head_b->next)
		sb_case_1(all, p1, p2, p3);
	if (all->checker_on == 0)
		write(1, "sb\n", 3);
}

int		sa_ss(t_ps *all)
{
	t_stack *p1;
	t_stack *p2;
	t_stack	*p3;

	p1 = NULL;
	p2 = NULL;
	p3 = NULL;
	if (all->head_a && all->head_a->next)
	{
		sa_case_1(all, p1, p2, p3);
		return (1);
	}
	return (0);
}

int		sb_ss(t_ps *all)
{
	t_stack *p1;
	t_stack *p2;
	t_stack	*p3;

	p1 = NULL;
	p2 = NULL;
	p3 = NULL;
	if (all->head_b && all->head_b->next)
	{
		sb_case_1(all, p1, p2, p3);
		return (1);
	}
	return (0);
}
