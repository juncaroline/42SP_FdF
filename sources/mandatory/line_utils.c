/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:39:48 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/08 15:23:27 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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
