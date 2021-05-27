/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:59:23 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/27 16:59:25 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	esc_exit(int key, t_params *vars)
{
	if (key == 53)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		exit(0);
	}
	return (0);
}
