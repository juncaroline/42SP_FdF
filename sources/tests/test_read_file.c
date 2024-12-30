/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:19:36 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/30 10:10:11 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#define BUFFER_SIZE 1024

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	nc;
	size_t	i;

	nc = (char)c;
	i = 0;
	while (s[i])
	{
		i++;
		if (s[i] == nc)
			return ((char *)(s + i));
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

static char	*rest(char *pile)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	while (pile[i] && pile[i] != '\n')
		i++;
	if (!pile[i])
		return (free(pile), NULL);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(pile) - i + 1));
	if (temp == NULL)
		return (NULL);
	i++;
	j = 0;
	while (pile[i])
		temp[j++] = pile[i++];
	temp[j] = '\0';
	free(pile);
	return (temp);
}

static char	*get_new(char *pile)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!pile[i])
		return (NULL);
	while (pile[i] && pile[i] != '\n')
		i++;
	if (pile[i] == '\n')
		i++;
	new = (char *)malloc(i + 1);
	if (new == NULL)
		return (NULL);
	i = -1;
	while (i++, pile[i] && pile[i] != '\n')
		new[i] = pile[i];
	if (pile[i] == '\n')
	{
		new[i] = pile[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	*join_pile(int fd, char *pile)
{
	int		bytes;
	char	*buffer;
	char	*temp;

	bytes = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free(pile), pile = NULL);
	while (!ft_strchr(pile, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(pile), pile = NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		temp = ft_strjoin(pile, buffer);
		free (pile);
		pile = temp;
	}
	return (free(buffer), pile);
}

char	*get_next_line(int fd)
{
	static char	*pile;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (pile == NULL)
		pile = ft_strdup("");
	pile = join_pile(fd, pile);
	if (pile == NULL)
		return (NULL);
	line = get_new(pile);
	pile = rest(pile);
	return (line);
}

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

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Uso: %s <arquivo.fdf>\n", argv[0]);
		return (1);
	}
	read_file(argv[1]);
	printf("Arquivo %s lido com sucesso!\n", argv[1]);
	return (0);
}