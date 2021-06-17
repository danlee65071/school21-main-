/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 21:18:05 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/11 21:18:06 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <errno.h>
# include "libft.h"

# define MAXITER 30
# define BLACK 0x00000000
# define GREEN 0x10B9FEBA
# define YELLOW 0x00E2FB28
# define RED 0x00C8210E
# define ESC_KEY 53
# define MOUSE_ZOOM_UP 4
# define MOUSE_ZOOM_DOWN 5
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_DOWN 125

typedef struct s_coord
{
	float	x;
	float	y;
}	t_coord;

typedef struct s_scene
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	t_coord	O1;
	t_coord	arrow_local;
	float	scale;
	char	fractol_name[20];
}	t_scene;

typedef struct s_complex
{
	float	re;
	float	im;
}	t_complex;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

void			my_mlx_pixel_put(t_scene *data, int x, int y, int color);
t_complex		complex_init(float re, float im);
float			complex_abs(t_complex complex_num);
void			complex_sqr(t_complex *complex_num);
t_complex		complex_sum(t_complex num1, t_complex num2);
void			fractol_Julia(t_scene *scene);
int				x_close(t_scene *scene);
int				keyboard(int key, t_scene *scene);
int				mouse_zoom(int button, int x, int y, t_scene *scene);
void			fractol_Mandelbrot(t_scene *scene);
int				ft_strcmp(char *s1, char *s2);
int				parse(int argc, char **argv, t_scene *scene);
void			get_fractol(t_scene *scene);
void			fractol_BurningShip(t_scene *scene);

#endif
