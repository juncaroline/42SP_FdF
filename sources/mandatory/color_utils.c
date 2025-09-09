/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:45:24 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/08 12:50:26 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	get_red(int color)
{
	return (color >> 16);
}

int	get_green(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_blue(int color)
{
	return (color & 0xFF);
}

int	get_alpha(int color)
{
	return (color >> 24);
}

int	get_rgba(int red, int green, int blue, int alpha)
{
	return (((alpha) << 24) + ((red) << 16) + ((green) << 8) + (blue));
}
