/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:42:56 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/12 20:42:58 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	in_set(int *a, int n, int i, int len_a)
{
	int	tmp;

	tmp = len_a - 1;
	while (--len_a > tmp - i)
		if (a[len_a] == n)
			return (1);
	return (0);
}

void	ft_parse_a(int **a, int *len_a, int argc, char **argv)
{
	int	i;
	int	n;

	*len_a = argc - 1;
	*a = malloc(sizeof(int) * (*len_a));
	if (!(*a))
		ft_error();
	i = -1;
	while (++i < *len_a)
	{
		n = ft_atoi(argv[i + 1]);
		if ((ft_strlen(argv[i + 1]) > 2 && (n == 0 || n == -1)) || \
			(argv[i + 1][0] != '0' && n == 0))
			ft_error();
		if (in_set(*a, n, i, *len_a))
			ft_error();
		(*a)[*len_a - i - 1] = n;
	}
}
