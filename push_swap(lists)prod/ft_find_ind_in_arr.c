/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_ind_in_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:59:58 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/20 14:00:00 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_ind_in_arr(const int *arr, int value)
{
	int	i;

	i = 0;
	while (arr[i] != value)
		i++;
	return (i);
}
