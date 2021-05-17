/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:40:37 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/12 17:40:40 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*new_a(int *a, int *len_a, int *b, int len_b)
{
	int	*tmp;
	int	i;

	(*len_a)++;
	tmp = malloc(sizeof(int) * (*len_a));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < *len_a - 1)
		tmp[i] = a[i];
	tmp[*len_a - 1] = b[len_b - 1];
	free(a);
	return (tmp);
}

static int	*new_b(int *b, int *len_b)
{
	int	*tmp;
	int	i;

	(*len_b)--;
	tmp = malloc(sizeof(int) * (*len_b));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < *len_b)
		tmp[i] = b[i];
	if (b)
		free(b);
	return (tmp);
}

void	ft_pa(int **a, int *len_a, int **b, int *len_b)
{
	if (*len_b >= 1)
	{
		*a = new_a(*a, len_a, *b, *len_b);
		*b = new_b(*b, len_b);
		if (!(*a) || !(*b))
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		else
			write(1, "pa\n", 3);
	}
}
