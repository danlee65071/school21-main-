/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:01:21 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/12 19:01:23 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(int **a, int len_a, int is_rr)
{
	int	*tmp;
	int	i;

	tmp = malloc(sizeof(int) * (len_a));
	if (!tmp)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	i = 0;
	tmp[0] = (*a)[len_a - 1];
	while (++i < len_a)
		tmp[i] = (*a)[i - 1];
	free(*a);
	*a = tmp;
	if (!is_rr)
		write(1, "ra\n", 3);
}
