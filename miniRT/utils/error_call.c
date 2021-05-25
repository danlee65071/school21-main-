/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_call.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:01:08 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/24 14:01:09 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	error_call(int error_code)
{
	strerror(error_code);
	exit (error_code);
}
