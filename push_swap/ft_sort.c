/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:56:11 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/15 21:56:14 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(int **a, int len_a)
{
	int	*sort_arr;
	int median;
	int *b;
	int	len_b;
	int i;

	len_b = 0;
	sort_arr = *a;
	ft_sort_arr(&sort_arr, len_a);
	median = ft_find_median(sort_arr, len_a);
	i = -1;
	while (++i < len_a)
	{
		if ((*a)[i] <= median)
		{
			ft_to_top(a, len_a, (*a)[i]);
			ft_pb(a, &len_a, &b, &len_b);
		}
	}
}
