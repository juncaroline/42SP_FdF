/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:05:14 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/30 18:32:29 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*parse(t_fdf *fdf, char *id_map)
{
	t_map	*map;

	map = new_map();
	map->width = receive_width(id_map);
	map->height = receive_height(id_map);
	if (map->width < 2 || map->height < 2)
	{
		free (fdf);
		free (map);
		error_msg(4);
	}
	map->matrix = alloc_matrix(map->width, map->height);
	convert_map(map, id_map);
	center_map(map);
	return (map);
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

int	receive_width(char *id_map)
{
	int		fd;
	int		count;
	char	*line;
	char	**div_line;

	count = 0;
	fd = open(id_map, O_RDONLY);
	line = get_next_line(fd);
	div_line = ft_split(line, ' ');
	while (div_line[count] && div_line[count][0] != '\n')
		count++;
	free (line);
	free_split(div_line);
	if (check_lines(fd, count) == -1)
		return (0);
	return (count);
}

int	receive_height(char *id_map)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(id_map, O_RDONLY);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	process_line(t_map *map, char **div_line, int i)
{
	int		j;
	char	*color;

	j = 0;
	while (j < map->width)
	{
		map->matrix[i][j].x = (float)j;
		map->matrix[i][j].y = (float)i;
		map->matrix[i][j].z = (float)ft_atoi(div_line[j]);
		if (map->matrix[i][j].z > map->z_top)
			map->z_top = map->matrix[i][j].z;
		color = ft_strchr(div_line[j], ',');
		if (color != NULL)
			map->matrix[i][j].color = put_alpha(ft_hex_to_int(color + 1));
		else
		{
			if (map->matrix[i][j].z <= 0)
				map->matrix[i][j].color = 0x0000FF;
			else
				map->matrix[i][j].color = 0xFF0000;
		}
		j++;
	}
}
