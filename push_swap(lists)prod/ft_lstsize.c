/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:42:52 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 17:42:53 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stacks *stack)
{
	int	len_stack;

	len_stack = 0;
	while (stack)
	{
		len_stack++;
		stack = stack->next;
	}
	return (len_stack);
}
