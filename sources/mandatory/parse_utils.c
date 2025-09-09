/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:26:56 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/04 14:50:30 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

uint32_t	put_alpha(uint32_t color)
{
	uint32_t		new;
	unsigned char	*ptr;

	new = color << 8;
	ptr = (unsigned char *)&new;
	*ptr = 255;
	return (new);
}

int	check_lines(int fd, int size)
{
	int		check;
	int		word_count;
	char	*line;
	char	**div_line;

	check = 1;
	word_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		div_line = ft_split(line, ' ');
		while (div_line[word_count] != NULL && div_line[word_count][0] != '\n')
			word_count++;
		if (word_count != size)
			check = 0;
		word_count = 0;
		free(line);
		free_split(div_line);
	}
	get_next_line(-1);
	return (check);
}

static int	process_map_line(t_map *map, char *line, int line_i)
{
	char	**div_line;

	div_line = ft_split(line, ' ');
	if (div_line == NULL)
	{
		error_msg(2);
		return (0);
	}
	if (process_line(map, div_line, line_i) == -1)
	{
		free_split(div_line);
		error_msg(3);
		return (0);
	}
	free_split(div_line);
	return (1);
}	

void	convert_map(t_map *map, char *id_map)
{
	int		line_i;
	int		fd;
	char	*line;

	fd = open(id_map, O_RDONLY);
	if (fd < 0)
	{
		error_msg(1);
		return ;
	}
	line_i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (!process_map_line(map, line, line_i))
		{
			free(line);
			break ;
		}
		free(line);
		line_i++;
	}
	close (fd);
}

void	center_map(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < (unsigned int)map->height)
	{
		x = 0;
		while (x < (unsigned int)map->width)
		{
			map->matrix[y][x].x -= map->width / 2;
			map->matrix[y][x].y -= map->height / 2;
			x++;
		}
		y++;
	}
}
