/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:42:09 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/28 11:31:50 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libraries/get_next_line/get_next_line.h"
# include "../libraries/libft/libft.h"
# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900

typedef struct	s_coordinates
{
	float		x;
	float		y;
	float		z;
	uint32_t	color;
}	t_coordinates;

typedef struct	s_map
{
    int				width;
    int				height;
	int				z_top;
	t_coordinates	**matrix;
}	t_map;

typedef struct s_draw_line
{
	int		dif_x;
	int		dif_y;
	int		calibrate;
	int		move_x;
	int		move_y;
}	t_draw_line;

typedef struct	s_camera
{
	float	x;
	float	y;
	float	z;
	float	scale;
}	t_camera;

typedef struct	s_fdf
{
	t_map		*map;
	t_camera	*camera;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_fdf;


#endif