/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:34:20 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/09 10:48:54 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, uint32_t color)
{
	if (x <= 0 || x >= WINDOW_WIDTH || y <= 0 || y >= WINDOW_HEIGHT)
		return ;
	mlx_put_pixel(fdf->img, x, y, color);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	new_line_data(t_draw_line *line, t_coordinates start,
	t_coordinates end)
{
	line->d_x = ft_abs(end.x - start.x);
	line->d_y = ft_abs(end.y - start.y);
	line->control = 0;
	if (end.x > start.x)
		line->inc_x = 1;
	else
		line->inc_x = -1;
	if (end.y > start.y)
		line->inc_y = 1;
	else
		line->inc_y = -1;
}

void	draw_line(t_fdf *fdf, t_coordinates start, t_coordinates end)
{
	t_draw_line	line;

	new_line_data(&line, start, end);
	if (line.d_x == 0)
		axis_y_line(fdf, start, end);
	else if (line.d_y == 0)
		axis_x_line(fdf, start, end);
	else
	{
		if (line.d_x >= line.d_y)
			diag_x_line(fdf, line, start, end);
		else
			diag_y_line(fdf, line, start, end);
	}
}
