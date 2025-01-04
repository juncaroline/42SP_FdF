/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:42:00 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/04 13:56:41 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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

t_camera	*cam_config(t_fdf *fdf)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (camera == NULL)
		error_msg(4);
	camera->scale = get_scale(fdf);
	camera->x = (WINDOW_WIDTH / 2);
	camera->y = (WINDOW_HEIGHT / 2);
	camera->z = 1;
	if (fdf->map->z_top <= 20)
		camera->z = 10;
	else if (fdf->map->z_top > 720)
		camera->z = 0.05;
	return (camera);
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
