/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:01:31 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 16:22:56 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*init_stack;
	int		count;
	t_ps	*all;

	all = NULL;
	init_stack = NULL;
	count = 0;
	init_stack = validator(ac, av);
	if (init_stack == NULL)
		error_exit();
	count = counter(av);
	if (count == 0)
		return (0);
	else if (count == 1)
		write(1, "OK\n", 3);
	else
	{
		all = foo_stacks(count, init_stack);
		all->checker_on = 1;
		reader(all);
		free_linked_lists(all);
	}
	free(init_stack);
	return (0);
}
