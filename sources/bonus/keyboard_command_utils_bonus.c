/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_command_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:44:36 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/09 12:36:34 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_bonus.h"

void	rotation(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		fdf->camera->y_rotation += 0.0175;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		fdf->camera->y_rotation -= 0.0175;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		fdf->camera->x_rotation += 0.0175;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->camera->x_rotation -= 0.0175;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
		fdf->camera->z_rotation += 0.0175;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
		fdf->camera->z_rotation -= 0.0175;
}

void	zoom(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_EQUAL))
		fdf->camera->scale += 0.3;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_MINUS))
		fdf->camera->scale -= 0.3;
}

void	projection(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_P))
		set_camera(fdf, ISOMETRIC);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_T))
		set_camera(fdf, TOP_VIEW);
}
