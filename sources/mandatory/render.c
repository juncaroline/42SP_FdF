/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:48:26 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/08 15:33:28 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	render(t_fdf *fdf)
{
	int	x;
	int	y;

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
	isometry(fdf, &start, &end);
	centralize(fdf, &start, &end);
	draw_line(fdf, start, end);
}
