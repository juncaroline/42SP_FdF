/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:42:09 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/30 12:58:40 by cabo-ram         ###   ########.fr       */
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

void	free_split(char **split);
int	check_lines(int fd, int size);
void	process_line(t_map *map, char **div_line, int i);
void	convert_map(t_map *map, char *id_map);
void	center_map(t_map *map);
t_coordinates	**alloc_matrix(int width, int height);
uint32_t	put_alpha(uint32_t color);
int	ft_hex_to_int(char *hexa);
void	keyboard_command(void *param);
t_fdf	*init_fdf(char *id_map);
void 	free_fdf(t_fdf *fdf);
void	put_pixel(t_fdf *fdf, int x, int y, uint32_t color);
void	draw_line(t_fdf *fdf, t_coordinates start, t_coordinates end);
void	error_msg(int status);
void	read_file(char *map);
t_map	*parse(t_fdf *fdf, char *id_map);
t_camera	*cam_config(t_fdf *fdf);
float	get_scale(t_fdf *fdf);

#endif