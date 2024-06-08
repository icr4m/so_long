/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:16:24 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/08 22:45:08 by ijaber           ###   ########.fr       */
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

bool	ft_parsing(t_map map)
{
	char	*line;
	size_t	len;

	map.fd = open(map.path, O_RDONLY);
	line = get_next_line(map.fd);
	len = ft_linelen(line);
	if (check_line(line, '1'))
	{
		while (line = get_next_line(map.fd))
		{
			len = ft_linelen(line);
			if (line[0] != '1' || line[len - 1] != '1')
				break ;
		}
		return (1);
	}
	ft_printf("Map is not good.");
	return (0);
}
