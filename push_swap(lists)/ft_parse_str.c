/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 12:54:31 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/16 12:54:33 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse_str(char *str, t_stacks **stack_a)
{
	char	**split_str;
	int		len_split_str;
	int 	i;

	split_str = ft_split(str, ' ');
	if (!split_str)
		ft_error();
	len_split_str = 0;
	while (split_str[len_split_str])
		len_split_str++;
	ft_parse(len_split_str, split_str, stack_a, 1);
	i = -1;
	while (++i < len_split_str)
		free(split_str[i]);
	free(split_str[i]);
	free(split_str);
}
