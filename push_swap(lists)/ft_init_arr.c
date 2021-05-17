/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:46:21 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 17:46:22 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_arr(int **arr, int len_arr, t_stacks *stacks)
{
	int	i;

	(*arr) = malloc(sizeof(int) * (len_arr));
	if (!(*arr))
		ft_error();
	i = -1;
	while (++i < len_arr)
	{
		(*arr)[i] = stacks->value;
		stacks = stacks->next;
	}
}
