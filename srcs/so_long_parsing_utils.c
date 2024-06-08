/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:57:25 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/08 21:56:10 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber_map(char *map)
{
	const size_t	len = ft_strlen(map);

	if (map[len - 1] == 'r' && map[len - 2] == 'e' && map[len - 3] == 'b')
		return (1);
	return (0);
}

int	check_line(char c, char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (c = line[i])
			return (1);
		i++;
	}
	return (NULL);
}
