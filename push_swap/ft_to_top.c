/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_top.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 23:25:44 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/15 23:25:45 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_to_top(int **arr, int len_arr, int ind_el)
{
	int	i;
	int	mid;

	mid = len_arr / 2;
	if (ind_el == len_arr - 1)
		return ;
	if (ind_el >= mid)
	{
		ft_rra(arr, len_arr, 0);
		if (!arr)
			exit(1);
	}
	else
	{
		ft_ra(arr, len_arr, 0);
		if (!arr)
			exit(1);
	}
}
