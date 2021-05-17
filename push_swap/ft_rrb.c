/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:08:24 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/12 20:08:26 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(int **b, int len_b, int is_rrr)
{
	int	*tmp;
	int	i;

	tmp = malloc(sizeof(int) * len_b);
	if (!tmp)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	tmp[0] = (*b)[len_b - 1];
	i = 0;
	while (++i < len_b - 1)
		tmp[i] = (*b)[i - 1];
	if (b)
		free(*b);
	*b = tmp;
	if (!is_rrr)
		write(1, "rra\n", 4);
}
