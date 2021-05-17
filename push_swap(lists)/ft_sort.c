/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:00:22 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 19:00:24 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stacks **stack_a, t_stacks **stack_b)
{
	int	*sorted_arr;
	int min_not_sorted_el;

	ft_init_arr(&sorted_arr, ft_lstsize(*stack_a), *stack_a);
	ft_sort_arr(&sorted_arr, ft_lstsize(*stack_a));
	min_not_sorted_el = sorted_arr[0];
	ft_set_indexes_in_sort_arr(stack_a, sorted_arr);
	ft_transfer_from_a_to_b(stack_a, stack_b);
	while (ft_lstsize(*stack_b))
	{
		ft_transfer_from_b_to_a(stack_a, stack_b, &min_not_sorted_el,
								sorted_arr);
		ft_is_in_place(stack_a, &min_not_sorted_el, sorted_arr);
	}
}
