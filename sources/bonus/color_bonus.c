/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:20:34 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/09/09 14:20:09 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_bonus.h"

int	gradient(int start, int end, int grad_len, int position)
{
	int		rgba[4];
	double	r;
	int		i;

	if (grad_len == 0)
		return (start);
	if (position >= grad_len)
		return (end);
	r = (double)position / (double)grad_len;
	rgba[0] = (int)(get_red(start) + (r * (get_red(end) - get_red(start))));
	rgba[1] = (int)(get_green(start) + (r * (get_green(end)
					- get_green(start))));
	rgba[2] = (int)(get_blue(start) + (r * (get_blue(end) - get_blue(start))));
	rgba[3] = (int)(get_alpha(start) + (r * (get_alpha(end)
					- get_alpha(start))));
	i = 0;
	while (i < 4)
	{
		if (rgba[i] < 0)
			rgba[i] = 0;
		else if (rgba[i] > 255)
			rgba[i] = 255;
		i++;
	}
	return (get_rgba(rgba[0], rgba[1], rgba[2], rgba[3]));
}
