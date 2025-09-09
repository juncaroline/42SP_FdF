/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:57:05 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/09/09 14:23:06 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_bonus.h"

static int	ft_total_steps_y(t_draw_line line, t_coordinates start,
	t_coordinates end)
{
	t_coordinates	temp_start;
	int				total_steps;

	temp_start = start;
	total_steps = 0;
	line.control = line.d_y / 2;
	while ((int)temp_start.y != (int)end.y)
	{
		temp_start.y += line.inc_y;
		line.control -= line.d_x;
		if (line.control < 0)
		{
			temp_start.x += line.inc_x;
			line.control += line.d_y;
		}
		total_steps++;
	}
	return (total_steps);
}

static int	ft_total_steps_x(t_draw_line line, t_coordinates start,
	t_coordinates end)
{
	t_coordinates	temp_start;
	int				total_steps;

	temp_start = start;
	total_steps = 0;
	line.control = line.d_x / 2;
	while ((int)temp_start.x != (int)end.x)
	{
		temp_start.x += line.inc_x;
		line.control -= line.d_y;
		if (line.control < 0)
		{
			temp_start.y += line.inc_y;
			line.control += line.d_x;
		}
		total_steps++;
	}
	return (total_steps);
}

void	axis_x_line(t_fdf *fdf, t_coordinates start, t_coordinates end)
{
	int		position;
	int		total_steps;
	bool	is_grad;

	total_steps = ft_abs((int)end.x - (int)start.x);
	position = 0;
	is_grad = (start.color != end.color);
	put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	while ((int)start.x != (int)end.x)
	{
		if (end.x > start.x)
			start.x++;
		else
			start.x--;
		position++;
		if (is_grad)
			put_pixel(fdf, (int)start.x, (int)start.y, gradient(start.color,
					end.color, total_steps, position));
		else
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	}
}

void	diag_x_line(t_fdf *fdf, t_draw_line line, t_coordinates start,
	t_coordinates end)
{
	int		position;
	int		total_steps;
	bool	is_grad;

	total_steps = ft_total_steps_x(line, start, end);
	position = 0;
	is_grad = (start.color != end.color);
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
		position++;
		if (is_grad)
			put_pixel(fdf, (int)start.x, (int)start.y,
				gradient(start.color, end.color, total_steps, position));
		else
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	}
}

void	diag_y_line(t_fdf *fdf, t_draw_line line, t_coordinates start,
	t_coordinates end)
{
	int		position;
	int		total_steps;
	bool	is_grad;

	total_steps = ft_total_steps_y(line, start, end);
	position = 0;
	is_grad = (start.color != end.color);
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
		position++;
		if (is_grad)
			put_pixel(fdf, (int)start.x, (int)start.y,
				gradient(start.color, end.color, total_steps, position));
		else
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	}
}
