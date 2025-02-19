/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:56:45 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/08 17:25:09 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_bonus.h"

void	scale(t_fdf *fdf, t_coordinates *start, t_coordinates *end)
{
	start->x *= fdf->camera->scale;
	start->y *= fdf->camera->scale;
	end->x *= fdf->camera->scale;
	end->y *= fdf->camera->scale;
}

void	isometry(t_fdf *fdf, t_coordinates *start, t_coordinates *end)
{
	t_coordinates	new_start;
	t_coordinates	new_end;

	new_start.x = (start->x - start->y) * cos(0.7071);
	new_start.y = (start->x + start->y) * sin(0.7071)
		- (start->z * fdf->camera->z_default);
	new_end.x = (end->x - end->y) * cos(0.7071);
	new_end.y = (end->x + end->y) * sin(0.7071)
		- (end->z * fdf->camera->z_default);
	start->x = new_start.x;
	start->y = new_start.y;
	end->x = new_end.x;
	end->y = new_end.y;
}

void	centralize(t_fdf *fdf, t_coordinates *start, t_coordinates *end)
{
	start->x += fdf->camera->x;
	start->y += fdf->camera->y;
	end->x += fdf->camera->x;
	end->y += fdf->camera->y;
}
