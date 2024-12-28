/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:19:42 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/11/11 12:28:31 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
