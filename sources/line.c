/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:34:20 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/30 18:20:21 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, uint32_t color)
{
	if (x <= 0 || x >= WINDOW_WIDTH || y <= 0 || y >= WINDOW_HEIGHT)
		return ;
	mlx_put_pixel(fdf->img, x, y, color);
}

void	new_line(t_draw_line *line, t_coordinates start, t_coordinates end)
{
	line->dif_x = fabsf(end.x - start.x);
	line->dif_y = fabsf(end.y - start.y);
	line->calibrate = 0;
	if (end.x > start.x)
		line->move_x = 1;
	else
		line->move_x = -1;
	if (end.y > start.y)
		line->move_y = 1;
	else
		line->move_y = -1;
}

void	draw_line(t_fdf *fdf, t_coordinates start, t_coordinates end)
{
	t_draw_line	line;

	new_line(&line, start, end);
	if (line.dif_x == 0)
		draw_vert(fdf, start, end);
	else if (line.dif_y == 0)
		draw_horiz(fdf, start, end);
	else
	{
		if (line.dif_x >= line.dif_y)
			draw_diag_x(fdf, line, start, end);
		else
			draw_diag_y(fdf, line, start, end);
	}
}
