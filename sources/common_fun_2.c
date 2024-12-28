/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_fun_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:41:21 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/28 17:20:02 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	put_alpha(uint32_t color)
{
	uint32_t		new;
	unsigned char	*ptr;

	new = color << 8;
	ptr = (unsigned char *)&new;
	*ptr = 255;
	return (new);
}

int	ft_hex_to_int(char *hexa)
{
	int	res;
	int	byte;

	res = 0;
	while (*hexa != ' ' && *hexa)
	{
		byte = *hexa++;
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		res = (res << 4) | (byte & 0xF);
	}
	return (res);
}
