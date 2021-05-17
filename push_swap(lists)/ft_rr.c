/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:51:09 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 11:51:10 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_stacks **stack_a, t_stacks **stack_b)
{
	ft_ra(stack_a, 1);
	ft_rb(stack_b, 1);
	write(1, "rr\n", 3);
}
