/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:33:51 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 17:33:53 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_arr(int **arr, int len_arr)
{
	int	i;
	int j;
	int	tmp;

	i = 0;
	while (i < len_arr)
	{
		j = len_arr - 1;
		while (j > i)
		{
			if ((*arr)[j - 1] > (*arr)[j])
			{
				tmp = (*arr)[j - 1];
				(*arr)[j - 1] = (*arr)[j];
				(*arr)[j] = tmp;
			}
			j--;
		}
		i++;
	}
}
