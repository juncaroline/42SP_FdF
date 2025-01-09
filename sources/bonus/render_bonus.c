/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:20:28 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/08 17:25:18 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_bonus.h"

void	render(void *param)
{
	t_fdf	*fdf;
	int		x;
	int		y;

	fdf = (t_fdf *)param;
	background(fdf);
	y = 0;
	while (y + 1 <= fdf->map->height)
	{
		x = 0;
		while (x + 1 <= fdf->map->width)
		{
			if (x + 1 < fdf->map->width)
				settings(fdf, fdf->map->matrix[y][x],
					fdf->map->matrix[y][x + 1]);
			if (y + 1 < fdf->map->height)
				settings(fdf, fdf->map->matrix[y][x],
					fdf->map->matrix[y + 1][x]);
			x++;
		}
		y++;
	}
}

void	background(t_fdf *fdf)
{
	uint32_t	*pixel;
	uint32_t	index;

	pixel = (uint32_t *)fdf->img->pixels;
	index = fdf->img->height * fdf->img->width;
	while (index--)
		pixel[index] = 0xff000000;
}

void	settings(t_fdf *fdf, t_coordinates start, t_coordinates end)
{
	scale(fdf, &start, &end);
	if (fdf->camera->projection == ISOMETRIC)
		isometry(fdf, &start, &end);
	rotate_x(fdf, &start, &end, fdf->camera->x_rotation);
	rotate_y(&start, &end, fdf->camera->y_rotation);
	rotate_z(&start, &end, fdf->camera->z_rotation);
	centralize(fdf, &start, &end);
	draw_line(fdf, start, end);
}
