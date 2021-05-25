/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:45:44 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/24 13:45:46 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx.h"
# include "vector.h"
# include "utils.h"
# include "sphere.h"
# include "camera.h"
# include "scene.h"
# include "view_plane.h"
//# include "sphere_intersection.h"

float	sphere_intersection(t_camera *camera, t_vector *ray, t_sphere *sphere);

#endif
