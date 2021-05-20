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

static void	ft_prepare_to_sort(t_stacks **stack_a, int **sorted_arr, int
								*min_not_sorted_el)
{
	ft_init_arr(sorted_arr, ft_lstsize(*stack_a), *stack_a);
	ft_sort_arr(sorted_arr, ft_lstsize(*stack_a));
	*min_not_sorted_el = (*sorted_arr)[0];
	ft_set_indexes_in_sort_arr(stack_a, *sorted_arr);
	if (ft_is_sorted_stack(*stack_a, *sorted_arr))
		exit (0);
}

static void	ft_rotate_stack_a(t_stacks **stack_a, t_stacks **stack_b,
							  int *min_not_sorted_el, int *sorted_arr)
{
	if (ft_lstsize(*stack_a) > 1
		&& (*stack_a)->next->value == *min_not_sorted_el
		&& (*stack_a)->value == sorted_arr[ft_find_ind_in_arr
			(sorted_arr, *min_not_sorted_el) + 1])
		ft_sa(stack_a, 0);
	else
		ft_pb(stack_a, stack_b);
}

static void	ft_instructions_in_last_while(t_stacks **stack_a,
										  t_stacks **stack_b,
										  int *min_not_sorted_el,
										  int *sorted_arr)
{
	ft_transfer_from_b_to_a(stack_a, stack_b, min_not_sorted_el,
		sorted_arr);
	ft_is_in_place(stack_a, min_not_sorted_el, sorted_arr);
}

void	ft_sort(t_stacks **stack_a, t_stacks **stack_b)
{
	int			*sorted_arr;
	int			min_not_sorted_el;

	ft_prepare_to_sort(stack_a, &sorted_arr, &min_not_sorted_el);
	ft_transfer_from_a_to_b(stack_a, stack_b);
	while (ft_lstsize(*stack_b))
	{
		ft_transfer_from_b_to_a(stack_a, stack_b, &min_not_sorted_el,
			sorted_arr);
		ft_is_in_place(stack_a, &min_not_sorted_el, sorted_arr);
	}
	if (ft_is_sorted_stack(*stack_a, sorted_arr))
		exit (0);
	while ((*stack_a)->value != sorted_arr[0])
	{
		while ((*stack_a)->value != min_not_sorted_el)
			ft_rotate_stack_a(stack_a, stack_b, &min_not_sorted_el, sorted_arr);
		if ((*stack_a)->value == min_not_sorted_el)
			ft_is_in_place(stack_a, &min_not_sorted_el, sorted_arr);
		while (ft_lstsize(*stack_b))
			ft_instructions_in_last_while(stack_a, stack_b,
				&min_not_sorted_el, sorted_arr);
	}
}
