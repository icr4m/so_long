/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:16:24 by ijaber            #+#    #+#             */
/*   Updated: 2024/05/29 08:46:39 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_parsing(char *path)
{
	int		fd;
	char	*buffer;
	size_t	b_size;

	fd = open(path, O_RDONLY);
	buffer = get_next_line(fd);
	b_size = ft_strlen(buffer);
	while (buffer)
	{
		buffer = get_next_line(fd);
		if (ft_strlen(buffer) != b_size)
			return (0);
	}
}

int	check_ber_map(char *map)
{
	const size_t len = ft_strlen(*map);

	if (map[len - 1] == 'r' && map[len - 2] == 'e' && map[len - 3] == 'b')
		return (1);
	return (0);
}