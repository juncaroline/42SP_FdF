/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:59:08 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/09/09 15:32:05 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_bonus.h"

t_map	*parse(char *id_map)
{
	t_map	*map;

	map = new_map();
	if (map == NULL)
		return (NULL);
	if (receive_width(id_map) == -1 || receive_height(id_map) == -1)
		return (free(map), NULL);
	map->width = receive_width(id_map);
	map->height = receive_height(id_map);
	if (map->width < 2 || map->height < 2)
	{
		if (map->matrix)
			free(map->matrix);
		free(map);
		return (NULL);
	}
	map->matrix = alloc_matrix(map->width, map->height);
	if (map->matrix == NULL)
	{
		free(map);
		return (NULL);
	}
	convert_map(map, id_map);
	center_map(map);
	return (map);
}

t_map	*new_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
	{
		error_msg(2);
		return (NULL);
	}
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

	fd = open(id_map, O_RDONLY);
	if (fd < 0)
		return (error_msg(1), -1);
	count = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (close(fd), -1);
	div_line = ft_split(line, ' ');
	free (line);
	if (div_line == NULL)
		return (close(fd), error_msg(2), -1);
	while (div_line[count] && div_line[count][0] != '\n')
		count++;
	free_split(div_line);
	if (!check_lines(fd, count))
		return (close(fd), 0);
	close(fd);
	return (count);
}

int	receive_height(char *id_map)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(id_map, O_RDONLY);
	if (fd < 0)
	{
		error_msg(1);
		return (-1);
	}
	height = 0;
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		return (-1);
	}
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	process_line(t_map *map, char **div_line, int i)
{
	int		j;
	char	*color;

	j = 0;
	while (j < map->width)
	{
		map->matrix[i][j].x = (float)j;
		map->matrix[i][j].y = (float)i;
		map->matrix[i][j].z = (float)(ft_atoi(div_line[j]));
		if (map->matrix[i][j].z > map->z_top)
			map->z_top = map->matrix[i][j].z;
		color = ft_strchr(div_line[j], ',');
		if (color)
			map->matrix[i][j].color = put_alpha(ft_hex_to_int(color + 1));
		else
		{
			if (map->matrix[i][j].z <= 0)
				map->matrix[i][j].color = 0xFF3333;
			else
				map->matrix[i][j].color = 0xFF3333FF;
		}
		j++;
	}
	return (0);
}
