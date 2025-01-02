/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:16:27 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/02 17:23:21 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_scount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
		if (*s == '\0')
			return (count);
		s++;
	}
	return (count);
}

static char	**ft_alloc(char **array, const char *s, int c)
{
	int	sstr;
	int	i;

	i = 0;
	while (*s)
	{
		sstr = 0;
		while (s[sstr] != c && s[sstr])
			sstr++;
		array[i] = (char *)ft_calloc((sstr + 1), sizeof(char));
		ft_strlcpy(array[i], s, sstr + 1);
		i++;
		while (*s != c && *s)
			s++;
		while (*s == c)
			s++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;

	if (!s)
		return (NULL);
	count = ft_scount(s, c);
	array = (char **)ft_calloc((count + 1), sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (*s == (unsigned char)c && *s)
		s++;
	ft_alloc(array, s, c);
	return (array);
}
