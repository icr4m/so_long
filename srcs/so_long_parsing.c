/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:16:24 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/09 00:59:25 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_parsing(t_vars *vars)
{
	char	*line;
	size_t	count;

	count = 1;
	vars->map.fd = open(vars->map.path, O_RDONLY);
	if (vars->map.fd < 0)
		error_map("Map not found.");
	line = get_next_line(vars->map.fd);
	vars->map.nb_c = ft_linelen(line);
	while (line = get_next_line(vars->map.fd))
	{
		if (ft_linelen(line) != vars->map.nb_c)
			error_map("Map is not rectangular.");
		count++;
	}
	close(vars->map.fd);
	vars->map.nb_l = count;
	return (1);
}
void fill_grid(t_vars *vars)
{
}
