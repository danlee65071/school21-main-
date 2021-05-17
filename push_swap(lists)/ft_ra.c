/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:50:44 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 11:50:45 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks **stack_a, int is_rr)
{
	t_stacks	*tmp;
	t_stacks	*del;

	tmp = ft_lstnew((*stack_a)->value, (*stack_a)->index_in_sort_arr,
					(*stack_a)->was_in_b);
	ft_lstadd_back(stack_a, tmp);
	del = (*stack_a);
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	free(del);
	if (!is_rr)
		write(1, "ra\n", 3);
}
