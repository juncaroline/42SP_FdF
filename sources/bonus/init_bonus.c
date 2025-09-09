/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:01:09 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/09 14:56:51 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_bonus.h"

t_fdf	*init_fdf(char *id_map)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
		error_msg(2);
	fdf->map = parse(id_map);
	if (fdf->map == NULL)
	{
		free(fdf);
		return (NULL);
	}
	fdf->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "FdF_bonus", 1);
	if (fdf->mlx == NULL)
		error_msg(3);
	fdf->img = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (fdf->img == NULL)
		error_msg(2);
	fdf->camera = cam_config(fdf);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	return (fdf);
}

void	set_camera(t_fdf *fdf, int projection_type)
{
	fdf->camera->projection = projection_type;
	fdf->camera->scale = get_scale(fdf);
	fdf->camera->x = WINDOW_WIDTH / 2;
	fdf->camera->y = WINDOW_HEIGHT / 2;
	fdf->camera->x_rotation = 0;
	fdf->camera->y_rotation = 0;
	fdf->camera->z_rotation = 0;
	if (fdf->map->width <= 500)
		fdf->camera->z_scale_resize = 0.5;
	else
		fdf->camera->z_scale_resize = 0.005;
	if (fdf->map->z_top <= 20)
		fdf->camera->z_default = 10;
	else if (fdf->map->z_top > 720)
		fdf->camera->z_default = 0.03;
	else
		fdf->camera->z_default = 1;
}

float	get_scale(t_fdf *fdf)
{
	float	scale;
	float	scale_x;
	float	scale_y;

	scale_x = WINDOW_WIDTH / (float)fdf->map->width;
	scale_y = WINDOW_HEIGHT / (float)fdf->map->height;
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	return (scale / 1.75);
}

t_camera	*cam_config(t_fdf *fdf)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (camera == NULL)
		error_msg(4);
	fdf->camera = camera;
	set_camera(fdf, ISOMETRIC);
	return (camera);
}
