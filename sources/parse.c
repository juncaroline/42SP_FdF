/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:05:14 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/28 15:24:43 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static int	receive_width(char *id_map)
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
	if (check_lines(fd, count) == NULL)
		return (0);
	return (count);
}

static int	receive_height(char *id_map)
{
	int		fd;
	int		height;
	char 	*line;

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
