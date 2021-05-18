/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:55:56 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 01:32:31 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sum(int count, const int *arr)
{
	int	res;

	res = 0;
	while (count > 0)
	{
		res = res + arr[count];
		count--;
	}
	return (res);
}
