/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part_of_the_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:24:12 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/17 17:24:13 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*ft_part_of_the_stack(t_stacks **stack)
{
	t_stacks	*part_of_the_stack;
	t_stacks	*stack_el_copy;

	part_of_the_stack = NULL;
	while ((*stack) && (*stack)->was_in_b < 1)
	{
		stack_el_copy = ft_lstnew((*stack)->value, (*stack)->index_in_sort_arr,
				(*stack)->was_in_b);
		ft_lstadd_back(&part_of_the_stack, stack_el_copy);
		ft_lstdel(stack);
		(*stack) = (*stack)->next;
	}
	return (part_of_the_stack);
}
