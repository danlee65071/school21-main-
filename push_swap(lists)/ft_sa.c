/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:49:52 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 11:49:53 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stacks	**stack_a, int is_ss)
{
	t_stacks	*swap;
	t_stacks	*del;

	del = (*stack_a)->next;
	(*stack_a)->next = del->next;
	del->next->prev = *stack_a;
	swap = ft_lstnew(del->value, del->index_in_sort_arr, del->was_in_b);
	if (!swap)
		ft_error();
	free(del);
	ft_lstadd_front(stack_a, swap);
	if (!is_ss)
		write(1, "sa\n", 3);
}
