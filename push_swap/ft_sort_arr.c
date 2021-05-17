/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 22:17:20 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/15 22:17:21 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap"

void	ft_sort_arr(int **arr, int len_arr)
{
	int new_element;
	int location;
	int i;

	i = 1;
	while (i < len_arr)
	{
		new_element = (*arr)[i];
		location  = i - 1;
		while (location >= 0 && (*arr)[location] > new_element)
		{
			(*arr)[location + 1] = (*arr)[location];
			location = location - 1;
		}
		(*arr)[location + 1] = new_element;
		i++;
	}
}
