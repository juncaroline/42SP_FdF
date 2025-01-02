/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:39:48 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/02 10:27:13 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_vert(t_fdf *fdf, t_coordinates start, t_coordinates end)
{
	if (end.y > start.y)
	{
		while ((int)start.y != (int)end.y)
		{
			start.y++;
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
		}
	}
	else
	{
		while ((int)start.y != (int)end.y)
		{
			start.y--;
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
		}
	}
}

void	draw_horiz(t_fdf *fdf, t_coordinates start, t_coordinates end)
{
	if (end.x > start.x)
	{
		while ((int)start.x != (int)end.x)
		{
			start.x++;
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
		}
	}
	else
	{
		while ((int)start.x != (int)end.x)
		{
			start.x--;
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
		}
	}
}

void	draw_diag_x(t_fdf *fdf, t_draw_line line, t_coordinates start,
	t_coordinates end)
{
	line.calibrate = line.dif_x / 2;
	put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	while ((int)start.x != (int)end.x)
	{
		start.x += line.move_x;
		line.calibrate -= line.dif_y;
		if (line.calibrate < 0)
		{
			start.y += line.move_y;
			line.calibrate += line.dif_x;
		}
		put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	}
}

void	draw_diag_y(t_fdf *fdf, t_draw_line line, t_coordinates start,
	t_coordinates end)
{
	line.calibrate = line.dif_y / 2;
	put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	while ((int)start.y != (int)end.y)
	{
		start.y += line.move_y;
		line.calibrate -= line.dif_x;
		if (line.calibrate < 0)
		{
			start.x += line.move_x;
			line.calibrate += line.dif_y;
		}
		put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	}
}
