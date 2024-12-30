/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:26:56 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/30 18:35:13 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

uint32_t	put_alpha(uint32_t color)
{
	uint32_t		new;
	unsigned char	*ptr;

	new = color << 8;
	ptr = (unsigned char *)&new;
	*ptr = 255;
	return (new);
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
