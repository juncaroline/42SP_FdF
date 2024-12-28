/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:59:27 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/28 14:27:48 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
