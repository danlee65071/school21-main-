/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:22:21 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/14 11:22:23 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

static int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static int	in_set(int *a, int n, int i, int len_a)
{
	int	tmp;

	tmp = len_a - 1;
	while (--len_a > tmp - i)
		if (a[len_a] == n)
			return (1);
	return (0);
}

void	parse_str(char *s, int **a, int *len_a)
{
	char	**tmp;
	int		n;
	int		i;

	tmp = ft_split(s,' ');
	if (!tmp)
		ft_error();
	*len_a = len_tab(tmp);
	*a = malloc(sizeof(int) * (*len_a));
	if (!(*a))
		ft_error();
	i = -1;
	while (++i < *len_a)
	{
		n = ft_atoi(tmp[i]);
		if ((ft_strlen(tmp[i]) > 2 && (n == 0 || n == -1)) || \
			(tmp[i][0] != '0' && n == 0))
			ft_error();
		if (in_set(*a, n, i, *len_a))
			ft_error();
		(*a)[*len_a - i - 1] = n;
	}
	free_tab(tmp);
}
