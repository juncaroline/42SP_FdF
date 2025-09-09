/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:09:39 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/09/09 14:21:57 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_bonus.h"

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

static void	new_line_data(t_draw_line *line, t_coordinates *start,
	t_coordinates *end)
{
	start->x = roundf(start->x);
	start->y = roundf(start->y);
	end->x = roundf(end->x);
	end->y = roundf(end->y);
	line->d_x = ft_abs(end->x - start->x);
	line->d_y = ft_abs(end->y - start->y);
	line->control = 0;
	if (end->x > start->x)
		line->inc_x = 1;
	else
		line->inc_x = -1;
	if (end->y > start->y)
		line->inc_y = 1;
	else
		line->inc_y = -1;
}

void	draw_line(t_fdf *fdf, t_coordinates start, t_coordinates end)
{
	t_draw_line	line;

	new_line_data(&line, &start, &end);
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

void	axis_y_line(t_fdf *fdf, t_coordinates start, t_coordinates end)
{
	int		position;
	int		total_steps;
	bool	is_grad;

	total_steps = ft_abs((int)end.y - (int)start.y);
	position = 0;
	is_grad = (start.color != end.color);
	put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	while ((int)start.y != (int)end.y)
	{
		if (end.y > start.y)
			start.y++;
		else
			start.y--;
		position++;
		if (is_grad)
			put_pixel(fdf, (int)start.x, (int)start.y, gradient(start.color,
					end.color, total_steps, position));
		else
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	}
}
