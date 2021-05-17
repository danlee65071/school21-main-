/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 22:47:37 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/15 22:47:39 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_median(int *arr, int len_arr)
{
	int	median;

	if (len_arr % 2 != 0)
		median = arr[len_arr / 2];
	else
		median = (arr[len_arr / 2] + arr[len_arr / 2 - 1]) / 2;
	return (median);
}
