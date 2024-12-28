/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:12:24 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/28 16:40:10 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	check_lines(int fd, int size)
{
	int		check;
	int		word_count;
	char	*line;
	char	**div_line;
	
	check = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		div_line = ft_split(line, ' ');
		word_count = 0;
		while (div_line[word_count] != NULL)
			word_count++;
		if (word_count != size)
			check = 0;
		free(line);
		free_split(div_line);
	}
	close(fd);
	get_next_line(-1);
	return (check);
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

void	convert_map(t_map *map, char *id_map)
{
	int		i;
	int		fd;
	char	*line;
	char	**div_line;

	i = 0;
	fd = open(id_map, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		div_line = ft_split(line, ' ');
		process_line(map, div_line, i);
		free_split(div_line);
		free(line);
		i++;
	}
	
}

