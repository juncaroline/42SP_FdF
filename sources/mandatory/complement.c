/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:41:21 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/04 13:56:47 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_coordinates	**alloc_matrix(int width, int height)
{
	t_coordinates	**matrix;
	int				i;

	matrix = malloc(sizeof(t_coordinates *) * height);
	if (matrix == NULL)
	{
		error_msg(2);
		return (NULL);
	}
	i = 0;
	while (i < height)
	{
		matrix[i] = ft_calloc(width, sizeof(t_coordinates));
		if (matrix[i] == NULL)
		{
			while (i > 0)
				free(matrix[--i]);
			free(matrix);
			error_msg(2);
			return (NULL);
		}
		i++;
	}
	return (matrix);
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

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_matrix(t_map *map)
{
	while (map->height--)
		free(map->matrix[map->height]);
	free(map->matrix);
}

void	free_all(t_fdf *fdf)
{
	if (fdf->map)
	{
		free_matrix(fdf->map);
		free(fdf->map);
	}
	if (fdf->camera)
		free(fdf->camera);
	free(fdf);
}
