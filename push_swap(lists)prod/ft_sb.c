/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:50:02 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 14:29:38 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sb_for_two_els(t_stacks **stack_b)
{
	t_stacks	*del;
	t_stacks	*tmp;

	del = *stack_b;
	tmp = ft_lstnew(del->value, del->index_in_sort_arr, del->was_in_b);
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev =NULL;
	(*stack_b)->next = tmp;
	free(del);
}

void	ft_sb(t_stacks	**stack_b, int is_ss)
{
	t_stacks	*swap;
	t_stacks	*del;

	if (ft_lstsize(*stack_b) < 2)
		exit (1);
	else if (ft_lstsize(*stack_b) == 2)
		ft_sb_for_two_els(stack_b);
	else
	{
		del = (*stack_b)->next;
		(*stack_b)->next = del->next;
		del->next->prev = *stack_b;
		swap = ft_lstnew(del->value, del->index_in_sort_arr, del->was_in_b);
		if (!swap)
			ft_error();
		free(del);
		ft_lstadd_front(stack_b, swap);
	}
	if (!is_ss)
		write(1, "sa\n", 3);
}
