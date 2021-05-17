/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:44:53 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/12 15:44:57 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*a;
	int len_a;

	if (argc < 2)
		exit (1);
	if (argc == 2)
		parse_str(argv[1], &a, &len_a);
	else
		ft_parse_a(&a, &len_a, argc, argv);

	return (0);
}