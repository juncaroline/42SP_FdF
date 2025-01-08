/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:39:48 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/08 15:06:53 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*static void	draw_vertical_gradient(t_fdf *fdf, t_coordinates start, t_coordinates end,
		int start_color, int end_color)
{
	int	position;
	int	grad_len;

	position = 0;
	grad_len = ft_abs((int)end.y - (int)start.y);

	while ((int)start.y != (int)end.y)
	{
		put_pixel(fdf, (int)start.x, (int)start.y,
			gradient(start_color, end_color, grad_len, position));
		if (end.y > start.y)
			start.y++;
		else
			start.y--;
		position++;
	}
}

void	draw_vert(t_fdf *fdf, t_coordinates start, t_coordinates end)
{
	int	position;
	int	grad_len;
	int	color;

	position = 0;
	grad_len = ft_abs((int)end.y - (int)start.y);
	if (start.color != end.color)
	{
		color = gradient(0xFF3333, 0x3333FF, grad_len, position);
		put_pixel(fdf, (int)start.x, (int)start.y, color);
		if (end.y > start.y)
			start.y++;
		else
			start.y--;
		position++;
	}
}*/

/*static void	draw_vert_grad(t_fdf *fdf, t_coordinates start, t_coordinates end)
{
	int	position;
	int	grad_len;
	int	start_color;
	int	end_color;

	position = 0;
	grad_len = ft_abs((int)end.y - (int)start.y);
	start_color = 0x3333FF;
	end_color = 0xFF3333;
	while ((int)start.y != (int)end.y)
	{
		put_pixel(fdf, (int)start.x, (int)start.y,
			gradient(start_color, end_color, grad_len, position));
		if (end.y > start.y)
			start.y++;
		else
			start.y--;
		position++;
	}
}

void	draw_vert(t_fdf *fdf, t_coordinates start, t_coordinates end)
{
	if (start.color != end.color)
		draw_vert_grad(fdf, start, end);
	else
	{
		while ((int)start.y != (int)end.y)
		{
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
			if (end.y > start.y)
				start.y++;
			else
				start.y--;
		}
	}
}*/

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
	int		position;
	int		grad_len;
	bool	is_grad;

	position = 0;
	grad_len = ft_abs(end.x - start.x);
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
			put_pixel(fdf, (int)start.x, (int)start.y, gradient(0xFF3333,
					0x3333FF, grad_len, position));
		else
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	}
}

void	draw_diag_y(t_fdf *fdf, t_draw_line line, t_coordinates start,
	t_coordinates end)
{
	int		position;
	int		grad_len;
	bool	is_grad;

	position = 0;
	grad_len = ft_abs(end.y - start.y);
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
			put_pixel(fdf, (int)start.x, (int)start.y, gradient(0xFF3333,
					0x3333FF, grad_len, position));
		else
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	}
}
