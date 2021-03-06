/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:14:25 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/12 19:14:28 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(int **a, int len_a, int **b, int len_b)
{
	ft_ra(a, len_a, 1);
	ft_rb(b, len_b, 1);
	write(1, "rr\n", 3);
}
