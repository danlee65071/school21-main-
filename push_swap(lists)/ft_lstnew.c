/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 12:16:24 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 12:16:25 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*ft_lstnew(int value, int ind_in_sort_arr, int was_in_b)
{
	t_stacks	*new_list;

	new_list = malloc(sizeof(t_stacks));
	if (!new_list)
		exit (1);
	new_list->value = value;
	new_list->index_in_sort_arr= ind_in_sort_arr;
	new_list->was_in_b = was_in_b;
	new_list->next = NULL;
	new_list->prev = NULL;
	return (new_list);
}
