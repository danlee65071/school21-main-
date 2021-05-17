/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:25:01 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/12 19:25:02 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(int **a, int len_a, int is_rrr)
{
	int	*tmp;
	int	i;

	tmp = malloc(sizeof(int) * len_a);
	if (!tmp)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	tmp[len_a - 1] = (*a)[0];
	i = -1;
	while (++i < len_a - 1)
		tmp[i] = (*a)[i + 1];
	free(*a);
	*a = tmp;
	if (!is_rrr)
		write(1, "rra\n", 4);
}
