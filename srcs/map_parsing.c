/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:16:24 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/09 05:07:06 by ijaber           ###   ########.fr       */
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

void	fill_grid(t_vars *vars)
{
	char	*line;
	t_point	pos;

	allocate_grid(vars, &pos);
	line = get_next_line(vars->map.fd);
	while (line)
	{
		allocate_line(vars, &pos);
		while (pos.co_x < vars->map.nb_c)
		{
			vars->map.grid[pos.co_y][pos.co_x] = line[pos.co_x];
			pos.co_x++;
		}
		vars->map.grid[pos.co_y][pos.co_x] = '\0';
		printf("La Grille %ld : %s\n", pos.co_y, vars->map.grid[pos.co_y]);
		pos.co_x = 0;
		pos.co_y++;
		line = get_next_line(vars->map.fd);
	}
}

void	check_wall(t_vars *vars)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < vars->map.nb_l)
	{
		if (vars->map.grid[x][y] != WALL)
			error_map("Map is not encased.");
		if (vars->map.grid[x][vars->map.nb_c - 1] != WALL)
			error_map("Map is not encased.");
		x++;
	}
	while (y < vars->map.nb_c)
	{
		if (vars->map.grid[0][y] != WALL)
			error_map("Map is not encased.");
		if (vars->map.grid[vars->map.nb_l - 1][y] != WALL)
			error_map("Map is not encased.");
		y++;
	}
}
