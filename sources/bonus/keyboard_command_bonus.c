/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_command_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:21:01 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/09/09 14:54:34 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_bonus.h"

void	keyboard_command(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	reset_view(fdf);
	movement(fdf);
	z_scale(fdf);
	rotation(fdf);
	zoom(fdf);
	projection(fdf);
}

void	reset_view(t_fdf *fdf)
{
	if (!mlx_is_key_down(fdf->mlx, MLX_KEY_R))
		return ;
	set_camera(fdf, fdf->camera->projection);
}

void	movement(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->camera->y -= 25;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->camera->y += 25;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->camera->x -= 25;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->camera->x += 25;
}

void	z_scale(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_U))
		fdf->camera->z_default += 0.05;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_F))
		fdf->camera->z_default -= 0.05;
}
