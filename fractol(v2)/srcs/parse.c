/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:53:13 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/12 15:53:14 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse(int argc, char **argv, t_scene *scene)
{
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "Julia") == 1)
			ft_strlcpy(scene->fractol_name, "Julia", 6);
		else if (ft_strcmp(argv[1], "Mandelbrot") == 1)
			ft_strlcpy(scene->fractol_name, "Mandelbrot", 11);
		else if (ft_strcmp(argv[1], "BurningShip") == 1)
			ft_strlcpy(scene->fractol_name, "BurningShip", 12);
		else
			return (0);
		return (1);
	}
	return (0);
}
