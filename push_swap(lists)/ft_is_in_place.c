/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:51:59 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/17 09:52:01 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_ind_in_arr(const int *arr, int value)
{
	int	i;

	i = 0;
	while (arr[i] != value)
		i++;
	return (i);
}

void	ft_is_in_place(t_stacks **stack, int *min_not_sorted_el, int
						*sorted_arr)
{
	if ((*stack)->value == *min_not_sorted_el && !ft_is_sorted_stack(*stack))
	{
		ft_ra(stack, 0);
		*min_not_sorted_el = sorted_arr[ft_find_ind_in_arr(sorted_arr,
								  		*min_not_sorted_el) + 1];
	}
}
