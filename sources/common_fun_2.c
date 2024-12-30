/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_fun_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:41:21 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/30 13:00:55 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_coordinates	**alloc_matrix(int width, int height)
{
	t_coordinates	**matrix;

	matrix = malloc(sizeof(t_coordinates *) * height);
	if (matrix == NULL)
		error_msg(2);
	while (height--)
	{
		matrix[height] = ft_calloc(width, sizeof(t_coordinates));
		if (matrix[height] == NULL)
			error_msg(2);
	}
	return (matrix);
}

uint32_t	put_alpha(uint32_t color)
{
	uint32_t		new;
	unsigned char	*ptr;

	new = color << 8;
	ptr = (unsigned char *)&new;
	*ptr = 255;
	return (new);
}

int	ft_hex_to_int(char *hexa)
{
	int	res;
	int	byte;

	res = 0;
	while (*hexa != ' ' && *hexa)
	{
		byte = *hexa++;
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		res = (res << 4) | (byte & 0xF);
	}
	return (res);
}

float	get_scale(t_fdf *fdf)
{
	float	scale;
	float	scale_x;
	float	scale_y;
	
	scale_x = WINDOW_WIDTH / (float)fdf->map->width;
	scale_y = WINDOW_HEIGHT / (float)fdf->map->height;
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	return (scale / 2);
}

t_map	*new_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		error_msg(2);
	map->width = 0;
	map->height = 0;
	map->z_top = 0;
	map->matrix = NULL;
	return (map);
}
