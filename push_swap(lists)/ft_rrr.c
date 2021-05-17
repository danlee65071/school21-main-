/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:51:41 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 11:51:42 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stacks **stack_a, t_stacks **stack_b)
{
	ft_rra(stack_a, 1);
	ft_rrb(stack_b, 1);
	write(1, "rrr\n", 4);
}
