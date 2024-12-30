/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:08:33 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/30 10:15:02 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
# include "../../libraries/MLX42/include/MLX42/MLX42.h"

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900

typedef struct	s_coordinates
{
	float		x;
	float		y;
	float		z;
	uint32_t	color;
}	t_coordinates;

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

typedef struct	s_map
{
    int				width;
    int				height;
	int				z_top;
	t_coordinates	**matrix;
}	t_map;

t_fdf	*init_fdf(char *id_map)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
		error_msg(2);
	fdf->map = parse(fdf, id_map);
	fdf->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "FdF", 1);
	if (fdf->mlx == NULL)
		error_msg(3);
	fdf->img = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (fdf->img == NULL)
		error_msg(2);
	fdf->camera = cam_config(fdf);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	return (fdf);
}