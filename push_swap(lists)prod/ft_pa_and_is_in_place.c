/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_and_is_in_place.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:39:59 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/20 19:40:00 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa_and_is_in_pl(t_stacks **stack_a, t_stacks **stack_b,
						   		int *min_not_sorted_el, int *sorted_arr)
{
	ft_pa(stack_a, stack_b);
	ft_is_in_place(stack_a, min_not_sorted_el, sorted_arr);
}
