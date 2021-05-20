/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_indexes_in_sort_arr.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:01:57 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 18:02:00 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_indexes_in_sort_arr(t_stacks **stack, int *sorted_arr)
{
	int			i;
	t_stacks	*passing;
	int			len_arr;

	passing = *stack;
	len_arr = ft_lstsize(*stack);
	i = 0;
	while (i < len_arr)
	{
		if (!passing)
			passing = *stack;
		if (passing->value == sorted_arr[i])
		{
			passing->index_in_sort_arr = i;
			i++;
		}
		passing = passing->next;
	}
}
