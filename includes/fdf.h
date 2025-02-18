/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:42:09 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/09 10:48:38 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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

typedef struct s_coordinates
{
	float		x;
	float		y;
	float		z;
	uint32_t	color;
}	t_coordinates;

typedef struct s_map
{
	int				width;
	int				height;
	float			z_top;
	t_coordinates	**matrix;
}	t_map;

typedef struct s_draw_line
{
	int		d_x;
	int		d_y;
	int		control;
	int		inc_x;
	int		inc_y;
}	t_draw_line;

typedef struct s_camera
{
	float	x;
	float	y;
	float	z;
	float	scale;
}	t_camera;

typedef struct s_fdf
{
	t_map		*map;
	t_camera	*camera;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_fdf;

//color.c color_utils.c
int				get_red(int color);
int				get_green(int color);
int				get_blue(int color);
int				get_alpha(int color);
int				get_rgba(int red, int green, int blue, int alpha);
int				gradient(int start, int end, int grad_len, int position);

//complement.c
t_coordinates	**alloc_matrix(int width, int height);
int				ft_hex_to_int(char *hexa);
void			free_split(char **split);
void			free_matrix(t_map *map);
void			free_all(t_fdf *fdf);

//init.c
t_fdf			*init_fdf(char *id_map);
t_camera		*cam_config(t_fdf *fdf);
float			get_scale(t_fdf *fdf);

//line.c / line_utils.c
void			put_pixel(t_fdf *fdf, int x, int y, uint32_t color);
int				ft_abs(int n);
void			draw_line(t_fdf *fdf, t_coordinates start, t_coordinates end);
void			axis_y_line(t_fdf *fdf, t_coordinates start, t_coordinates end);
void			axis_x_line(t_fdf *fdf, t_coordinates start, t_coordinates end);
void			diag_x_line(t_fdf *fdf, t_draw_line line, t_coordinates start,
					t_coordinates end);
void			diag_y_line(t_fdf *fdf, t_draw_line line, t_coordinates start,
					t_coordinates end);

//main.c
void			error_msg(int status);
void			read_file(char *map);
void			keyboard_command(void *param);

//parse.c / parse_utils.c
t_map			*parse(char *id_map);
t_map			*new_map(void);
int				receive_width(char *id_map);
int				receive_height(char *id_map);
int				process_line(t_map *map, char **div_line, int i);
uint32_t		put_alpha(uint32_t color);
int				check_lines(int fd, int size);
void			convert_map(t_map *map, char *id_map);
void			center_map(t_map *map);

//render.c / render_utils.c
void			render(t_fdf *fdf);
void			background(t_fdf *fdf);
void			settings(t_fdf *fdf, t_coordinates start, t_coordinates end);
void			scale(t_fdf *fdf, t_coordinates *start, t_coordinates *end);
void			isometry(t_fdf *fdf, t_coordinates *start, t_coordinates *end);
void			centralize(t_fdf *fdf, t_coordinates *start,
					t_coordinates *end);

#endif