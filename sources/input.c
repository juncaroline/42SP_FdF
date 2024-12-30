/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:59:27 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/30 12:48:32 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
