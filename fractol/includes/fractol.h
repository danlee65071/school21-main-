/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:19:42 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/04 15:19:44 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define MAXITER 100

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_complex
{
	float	re;
	float	im;
}	t_complex;

typedef struct	s_view
{
	int	x;
	int y;
}	t_view;

typedef struct	s_scene
{
	void	*mlx;
	void	*window;
	t_data	img;
	int 	width;
	int 	hight;
	t_view	view;
	float	scale;
}	t_scene;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		fractol_Julia(t_scene *scene);
t_complex	sqrt_complex(t_complex z);
float		abs_complex(t_complex z);
t_complex	complex_init(float re, float im);
t_complex	complex_sum(t_complex z1, t_complex z2);
float		init_radius(t_complex c);
int			create_trgb(int t, int r, int g, int b);
int			x_close(t_scene *scene);
int			esc_close(int key, t_scene *scene);

#endif
