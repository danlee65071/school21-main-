/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_el_wich_was_in_b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:50:10 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/18 10:50:12 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*ft_top_el_wich_was_in_b(t_stacks **stack)
{
	t_stacks	*top_el_wich_was_in_b;
	t_stacks	*stack_el_copy;

	top_el_wich_was_in_b = NULL;
	while (*stack && (*stack)->was_in_b > 0)
	{
		stack_el_copy = ft_lstnew((*stack)->value, (*stack)->index_in_sort_arr,
				(*stack)->was_in_b);
		ft_lstadd_back(&top_el_wich_was_in_b, stack_el_copy);
		ft_lstdel(stack);
		*stack = (*stack)->next;
	}
	return (top_el_wich_was_in_b);
}
