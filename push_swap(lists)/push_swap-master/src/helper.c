/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 20:35:22 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 01:30:59 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "error\n", 6);
	exit(EXIT_FAILURE);
}

int		counter(char **av)
{
	int		count;
	int		i;
	int		j;
	char	**temp;

	count = 0;
	i = 0;
	while (av[++i] != NULL)
	{
		j = 0;
		temp = ft_strsplit(av[i], ' ');
		while (temp[j++] != NULL)
			count++;
		while (--j != -1)
			free(temp[j]);
		free(temp);
		temp = NULL;
	}
	return (count);
}
