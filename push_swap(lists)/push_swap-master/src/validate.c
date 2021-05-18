/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:18:41 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 16:29:58 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_dooble(int count, int *av)
{
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (av[i] == av[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_only_number(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ' || av[i][j] == '\n' || av[i][j] == '\t' \
				|| av[i][j] == '\f' || av[i][j] == '\v' || av[i][j] == '\r')
				j++;
			if (((av[i][j] == '-' || av[i][j] == ' ') && (av[i][j + 1] \
			!= '-' || av[i][j + 1] != ' ')) || ((av[i][j] == '+' || \
			av[i][j] == ' ') && (av[i][j + 1] != '+' || av[i][j + 1] != ' ')))
				j++;
			if (!ft_isdigit(av[i][j]) && av[i][j] != '\0')
				return (0);
			while (ft_isdigit(av[i][j]))
				j++;
			if (av[i][j] != '\t' && av[i][j] != ' ' && av[i][j] != '\0')
				return (0);
		}
	}
	return (1);
}

int		*validator(int ac, char **av)
{
	int	i;
	int	count;
	int	*init_stack;

	i = 0;
	count = 0;
	init_stack = NULL;
	if (ac >= 2 && check_only_number(ac, av) == 1)
	{
		count = counter(av);
		init_stack = convert(count, av);
	}
	else
		return (init_stack);
	if (check_dooble(count, init_stack) != 1)
	{
		free(init_stack);
		return (NULL);
	}
	return (init_stack);
}
