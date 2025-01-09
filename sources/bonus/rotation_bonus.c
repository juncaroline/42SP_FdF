/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:23:14 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/09 15:27:37 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_bonus.h"

void	rotate_x(t_fdf *fdf, t_coordinates *start, t_coordinates *end,
	float angle)
{
	t_coordinates	new_start;
	t_coordinates	new_end;
	float			cos_angle;
	float			sin_angle;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	new_start.y = start->y * cos_angle - (start->z * fdf->camera->z_default)
		* sin_angle;
	new_start.z = start->y * sin_angle + (start->z * fdf->camera->z_default)
		* cos_angle;
	new_end.y = end->y * cos_angle - (end->z * fdf->camera->z_default)
		* sin_angle;
	new_end.z = end->y * sin_angle + (end->z * fdf->camera->z_default)
		* cos_angle;
	start->y = new_start.y;
	start->z = new_start.z;
	end->y = new_end.y;
	end->z = new_end.z;
}

void	rotate_y(t_coordinates *start, t_coordinates *end, float angle)
{
	t_coordinates	new_start;
	t_coordinates	new_end;
	float			cos_angle;
	float			sin_angle;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	new_start.x = start->x * cos_angle + start->z * sin_angle;
	new_start.z = start->x * sin_angle + start->z * cos_angle;
	new_end.x = end->x * cos_angle + end->z * sin_angle;
	new_end.z = end->x * sin_angle + end->z * cos_angle;
	start->x = new_start.x;
	start->z = new_start.z;
	end->x = new_end.x;
	end->z = new_end.z;
}

void	rotate_z(t_coordinates *start, t_coordinates *end, float angle)
{
	t_coordinates	new_start;
	t_coordinates	new_end;
	float			cos_angle;
	float			sin_angle;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	new_start.x = start->x * cos_angle - start->y * sin_angle;
	new_start.y = start->x * sin_angle + start->y * cos_angle;
	new_end.x = end->x * cos_angle - end->y * sin_angle;
	new_end.y = end->x * sin_angle + end->y * cos_angle;
	start->x = new_start.x;
	start->y = new_start.y;
	end->x = new_end.x;
	end->y = new_end.y;
}
