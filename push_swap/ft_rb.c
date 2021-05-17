/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:09:40 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/12 19:09:42 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(int **b, int len_b, int is_rr)
{
	int	*tmp;
	int	i;

	tmp = malloc(sizeof(int) * (len_b));
	if (!tmp)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	i = -1;
	while (++i < len_b - 2)
		tmp[i] = (*b)[i + 1];
	tmp[len_b - 1] = (*b)[0];
	if (b)
		free(*b);
	*b = tmp;
	if (!is_rr)
		write(1, "rb\n", 3);
}
