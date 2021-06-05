/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 20:56:42 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/05 20:56:44 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	esc_close(int key, t_scene *scene)
{
	if (key == 53)
	{
		mlx_destroy_window(scene->mlx, scene->window);
		exit(0);
	}
	printf("%d\n", key);
	return (0);
}
