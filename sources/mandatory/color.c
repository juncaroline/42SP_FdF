/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:20:14 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/09/09 14:18:14 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	gradient(int start, int end, int grad_len, int position)
{
	double	increment[4];
	int		new[4];
	int		new_color;

	increment[0] = (double)(get_red(end) - get_red(start))
		/ (double)grad_len;
	increment[1] = (double)(get_green(end) - get_green(start))
		/ (double)grad_len;
	increment[2] = (double)(get_blue(end) - get_blue(start))
		/ (double)grad_len;
	increment[3] = (double)(get_alpha(end) - get_alpha(start))
		/ (double)grad_len;
	new[0] = get_red(start) + round(increment[0] * position);
	new[1] = get_green(start) + round(increment[1] * position);
	new[2] = get_blue(start) + round(increment[2] * position);
	new[3] = get_alpha(start) + round(increment[3] * position);
	new_color = get_rgba(new[0], new[1], new[2], new[3]);
	return (put_alpha(new_color));
}
