/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:16:24 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/05 16:50:28 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_is_rectangular(t_map map)
{
	char	*line;
	size_t	length;

	map.fd = open(map.path, O_RDONLY);
	line = get_next_line(map.fd);
	length = ft_linelen(line);
	while (line)
	{
		if (ft_linelen(line) != length)
			ft_printf("Map is not rectangular.\n");
		line = get_next_line(map.fd);
	}
}

void	ft_fill_map(t_map map)
{
	t_point map_pos;

	map_pos.px_x = 0;
	map_pos.px_y = 0;
	
}