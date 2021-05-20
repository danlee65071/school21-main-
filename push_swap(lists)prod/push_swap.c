/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:46:09 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 11:46:10 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	*stack_a;
	t_stacks	*stack_b;

	if (argc < 2)
		exit (1);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		ft_parse_str(argv[1], &stack_a);
	else
		ft_parse(argc, argv, &stack_a, 0);
	ft_sort(&stack_a, &stack_b);
	return (0);
}
