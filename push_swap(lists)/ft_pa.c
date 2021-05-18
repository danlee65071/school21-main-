/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:50:21 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 11:50:23 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*tmp;
	t_stacks	*del;

	tmp = ft_lstnew((*stack_b)->value, (*stack_b)->index_in_sort_arr,
				 	(*stack_b)->was_in_b);
	ft_lstadd_front(stack_a, tmp);
	del = *stack_b;
	if ((*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
	}
	else
		*stack_b = NULL;
	free(del);
	write(1, "pa\n", 3);
}
