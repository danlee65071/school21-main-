/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:50:58 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 11:50:59 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_stacks **stack_b, int is_rr)
{
	t_stacks	*tmp;
	t_stacks	*del;

	tmp = ft_lstnew((*stack_b)->value, (*stack_b)->index_in_sort_arr,
			(*stack_b)->was_in_b);
	ft_lstadd_back(stack_b, tmp);
	del = (*stack_b);
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	free(del);
	if (!is_rr)
		write(1, "rb\n", 3);
}
