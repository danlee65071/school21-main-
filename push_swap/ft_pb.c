/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:03:19 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/12 18:03:21 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*new_b(int *a, int len_a, int *b, int *len_b)
{
	int	*tmp;
	int	i;

	(*len_b)++;
	tmp = malloc(sizeof(int) * (*len_b));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < *len_b - 1)
		tmp[i] = b[i];
	tmp[*len_b - 1] = a[len_a - 1];
	if (b)
		free(b);
	return (tmp);
}

static int	*new_a(int *a, int *len_a)
{
	int	*tmp;
	int	i;

	(*len_a)--;
	tmp = malloc(sizeof(int) * (*len_a));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < *len_a)
		tmp[i] = a[i];
	free(a);
	return (tmp);
}

void	ft_pb(int **a, int *len_a, int **b, int *len_b)
{
	if (*len_a >= 1)
	{
		*b = new_b(*a, *len_a, *b, len_b);
		*a = new_a(*a, len_a);
		if (!(*a) || !(*b))
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		else
			write(1, "pb\n", 3);
	}
}
