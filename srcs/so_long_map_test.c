/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:16:24 by ijaber            #+#    #+#             */
/*   Updated: 2024/05/29 16:35:00 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_parsing(char *path)
{
	int		fd;
	char	*line;
	size_t	length;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	length = ft_linelen(line);
	while (line)
	{
		if (ft_linelen(line) != length)
			return (0);
		line = get_next_line(fd);
	}
	
	return (1);
}

int	check_ber_map(char *map)
{
	const size_t len = ft_strlen(map);

	if (map[len - 1] == 'r' && map[len - 2] == 'e' && map[len - 3] == 'b')
		return (1);
	return (0);
}