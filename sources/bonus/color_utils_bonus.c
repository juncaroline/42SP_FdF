/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:20:27 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/09/09 14:20:27 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_bonus.h"

int	get_red(int color)
{
	return ((color >> 24) & 0xFF);
}

int	get_green(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_blue(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_alpha(int color)
{
	return (color & 0xFF);
}

int	get_rgba(int red, int green, int blue, int alpha)
{
	return ((red << 24) | (green << 16) | (blue << 8) | alpha);
}
