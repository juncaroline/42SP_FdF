/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:33:38 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/09 15:10:26 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

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
# define ISOMETRIC 0
# define TOP_VIEW 1

typedef struct s_coordinates
{
	float		x;
	float		y;
	float		z;
	int			point;
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
	float	z_default;
	float	z_scale_resize;
	float	scale;
	float	x_rotation;
	float	y_rotation;
	float	z_rotation;
	int		projection;
}	t_camera;

typedef struct s_fdf
{
	t_map		*map;
	t_camera	*camera;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_fdf;

//color_bonus.c color_utils_bonus.c
int				get_red(int color);
int				get_green(int color);
int				get_blue(int color);
int				get_alpha(int color);
int				get_rgba(int red, int green, int blue, int alpha);
int				gradient(int start, int end, int grad_len, int position);

//complement_bonus.c
t_coordinates	**alloc_matrix(int width, int height);
int				ft_hex_to_int(char *hexa);
void			free_split(char **split);
void			free_matrix(t_map *map);
void			free_all(t_fdf *fdf);

//init_bonus.c
t_fdf			*init_fdf(char *id_map);
void			set_camera(t_fdf *fdf, int projection_type);
float			get_scale(t_fdf *fdf);
t_camera		*cam_config(t_fdf *fdf);

//keyboard_command_bonus.c \ keyboard_command_utils_bonus.c
void			keyboard_command(void *param);
void			reset_view(t_fdf *fdf);
void			movement(t_fdf *fdf);
void			z_scale(t_fdf *fdf);
void			rotation(t_fdf *fdf);
void			zoom(t_fdf *fdf);
void			projection(t_fdf *fdf);

//line_bonus.c / line_utils_bonus.c
void			put_pixel(t_fdf *fdf, int x, int y, uint32_t color);
int				ft_abs(int n);
void			draw_line(t_fdf *fdf, t_coordinates start, t_coordinates end);
void			axis_y_line(t_fdf *fdf, t_coordinates start, t_coordinates end);
void			axis_x_line(t_fdf *fdf, t_coordinates start, t_coordinates end);
void			diag_x_line(t_fdf *fdf, t_draw_line line, t_coordinates start,
					t_coordinates end);
void			diag_y_line(t_fdf *fdf, t_draw_line line, t_coordinates start,
					t_coordinates end);

//main_bonus.c
void			error_msg(int status);
void			read_file(char *map);
void			keyboard_command(void *param);

//parse_bonus.c / parse_utils_bonus.c
t_map			*parse(char *id_map);
t_map			*new_map(void);
int				receive_width(char *id_map);
int				receive_height(char *id_map);
int				process_line(t_map *map, char **div_line, int i);
int				check_lines(int fd, int size);
uint32_t		put_alpha(uint32_t color);
void			convert_map(t_map *map, char *id_map);
void			center_map(t_map *map);

//render_bonus.c / render_utils_bonus.c
void			render(void *param);
void			background(t_fdf *fdf);
void			settings(t_fdf *fdf, t_coordinates start, t_coordinates end);
void			scale(t_fdf *fdf, t_coordinates *start, t_coordinates *end);
void			isometry(t_fdf *fdf, t_coordinates *start, t_coordinates *end);
void			centralize(t_fdf *fdf, t_coordinates *start,
					t_coordinates *end);

//rotation_bonus.c
void			rotate_x(t_fdf *fdf, t_coordinates *start, t_coordinates *end,
					float angle);
void			rotate_y(t_coordinates *start, t_coordinates *end, float angle);
void			rotate_z(t_coordinates *start, t_coordinates *end, float angle);

#endif