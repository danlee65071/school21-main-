/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:50:31 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 11:50:32 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*tmp;
	t_stacks	*del;

	tmp = ft_lstnew((*stack_a)->value, (*stack_a)->index_in_sort_arr,
			(*stack_a)->was_in_b);
	ft_lstadd_front(stack_b, tmp);
	del = *stack_a;
	if ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
	}
	else
		*stack_a = NULL;
	free(del);
	write(1, "pb\n", 3);
}
