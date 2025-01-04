/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:57:05 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/04 15:05:30 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_bonus.h"

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
	line.control = line.d_x / 2;
	put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	while ((int)start.x != (int)end.x)
	{
		start.x += line.inc_x;
		line.control -= line.d_y;
		if (line.control < 0)
		{
			start.y += line.inc_y;
			line.control += line.d_x;
		}
		put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	}
}

void	draw_diag_y(t_fdf *fdf, t_draw_line line, t_coordinates start,
	t_coordinates end)
{
	line.control = line.d_y / 2;
	put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	while ((int)start.y != (int)end.y)
	{
		start.y += line.inc_y;
		line.control -= line.d_x;
		if (line.control < 0)
		{
			start.x += line.inc_x;
			line.control += line.d_y;
		}
		put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	}
}
