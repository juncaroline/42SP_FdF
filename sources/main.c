/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:32:10 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/28 14:35:53 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_msg(int status)
{
	if (status == 1)
		ft_putstr_fd("Please insert a valid file. i.e.: ./fdf 'file'\n", 1);
	else if (status == 2)
		ft_putstr_fd("Failed to allocate memory!\n", 1);
	else if (status == 3)
		ft_putstr_fd("Failed to create image!\n", 1);
	else if (status == 4)
		ft_putstr_fd("Invalid map file.\n", 1);
	exit(status);
}

void	read_file(char *map)
{
	int		fd;
	char	*content;

	if (ft_strnstr(map, ".fdf", ft_strlen(map)) == NULL)
		ft_putstr_fd("Invalid map\n", 1);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("Error opening file\n", 1);
	content = get_next_line(fd);
	if (content == NULL)
		ft_putstr_fd("No map to show\n", 1);
	free(content);
	get_next_line(-1);
	close(fd);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		error_msg(1);
}
