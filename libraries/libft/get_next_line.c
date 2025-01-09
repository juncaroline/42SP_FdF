/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:19:42 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/09 11:40:25 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*update(char *buffer)
{
	char	*new_buffer;
	char	*new_line;

	new_line = ft_strchr(buffer, '\n');
	if (new_line == NULL)
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_strdup(new_line + 1);
	free(buffer);
	return (new_buffer);
}

static char	*get_new(char *content)
{
	char	*line;
	size_t	line_size;
	char	*new_pos;

	if (content[0] == '\0')
		return (NULL);
	new_pos = ft_strchr(content, '\n');
	if (new_pos == NULL)
		return (ft_strdup(content));
	else
		line_size = (new_pos - content) + 2;
	line = malloc(sizeof(char) * line_size);
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, content, line_size);
	return (line);
}

static char	*join_free(char const *s1, char const *s2)
{
	char	*new;
	size_t	new_len;

	if (s1 == NULL)
		s1 = ft_strdup("");
	new_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(new_len * sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, new_len);
	ft_strlcat(new, s2, new_len);
	free((char *)s1);
	return (new);
}

static char	*read_file(int fd, char *buffer)
{
	char	*file;
	ssize_t	bytes;

	if (ft_strchr(buffer, '\n'))
		return (buffer);
	file = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (file == NULL)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes)
	{
		bytes = read(fd, file, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(file);
			free(buffer);
			return (NULL);
		}
		file[bytes] = '\0';
		buffer = join_free(buffer, file);
	}
	free(file);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*pile;

	if (fd < 0)
	{
		free(pile);
		pile = NULL;
		return (NULL);
	}
	pile = read_file(fd, pile);
	if (pile == NULL)
		return (NULL);
	line = get_new(pile);
	pile = update(pile);
	return (line);
}
