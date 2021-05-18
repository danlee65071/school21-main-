/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:06:29 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 19:06:31 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_median(t_stacks *stack)
{
	int	median;
	int len_stack;
	int *sorted_arr;

	len_stack = ft_lstsize(stack);
	median = 0;
	ft_init_arr(&sorted_arr, len_stack, stack);
	ft_sort_arr(&sorted_arr, len_stack);
	if (len_stack % 2 != 0)
		median = sorted_arr[len_stack / 2];
	else
		median = (sorted_arr[len_stack / 2] + sorted_arr[len_stack / 2 - 1]) / 2;
	return (median);
}
