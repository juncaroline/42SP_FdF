/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:32:10 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/30 12:08:16 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	else if (status == 5)
		ft_putstr_fd("Error opening file.\n", 1);
	else if (status == 6)
		ft_putstr_fd("No map to show.\n", 1);
	exit(status);
}

void	read_file(char *map)
{
	int		fd;
	char	*content;

	if (ft_strnstr(map, ".fdf", ft_strlen(map)) == NULL)
		error_msg(4);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_msg(5);
	content = get_next_line(fd);
	if (content == NULL)
	{
		close(fd);
		error_msg(6);
	}
	free(content);
	get_next_line(-1);
	close(fd);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		error_msg(1);
	read_file(av[1]);
}
