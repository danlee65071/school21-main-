/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:51:19 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 11:51:20 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stacks **stack_a, int is_rrr)
{
	t_stacks	*tmp;
	t_stacks	*del;

	del = ft_lstlast(*stack_a);
	tmp = ft_lstnew(del->value, del->index_in_sort_arr, del->was_in_b);
	ft_lstadd_front(stack_a, tmp);
	del->prev->next = NULL;
	free(del);
	if (!is_rrr)
		write(1, "rra\n", 4);
}
