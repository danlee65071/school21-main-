/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:51:28 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 11:51:30 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(t_stacks **stack_b, int is_rrr)
{
	t_stacks	*tmp;
	t_stacks	*del;

	del = ft_lstlast(*stack_b);
	tmp = ft_lstnew(del->value, del->index_in_sort_arr, del->was_in_b);
	ft_lstadd_front(stack_b, tmp);
	del->prev->next = NULL;
	free(del);
	if (!is_rrr)
		write(1, "rrb\n", 4);
}
