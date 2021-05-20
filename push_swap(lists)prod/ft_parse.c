/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 12:06:25 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 12:06:27 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse(int argc, char **argv, t_stacks **stack_a, int is_str_parse)
{
	int	i;
	int	n;

	if (is_str_parse)
		i = -1;
	else
		i = 0;
	while (++i < argc)
	{
		n = ft_atoi(argv[i]);
		if ((ft_strlen(argv[i]) > 2 && (n == 0 || n == -1)) || \
			(argv[i][0] != '0' && n == 0) || ft_is_el_in_list(*stack_a, n))
			ft_error();
		ft_lstadd_back(stack_a, ft_lstnew(n, 0, 0));
	}
}
