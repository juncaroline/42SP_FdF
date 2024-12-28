/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:34:20 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/28 13:37:00 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, uint32_t color)
{
	if (x <= 0 || x >= WINDOW_WIDTH || y <= 0 || y >= WINDOW_HEIGHT)
		return ;
	mlx_put_pixel(fdf->img, x, y, color);
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

