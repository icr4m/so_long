/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:57:25 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/23 16:20:26 by ijaber           ###   ########.fr       */
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

size_t	ft_linelen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	allocate_grid_cell(t_vars *vars, t_point *pos)
{
	pos->co_x = 0;
	pos->co_y = 0;
	vars->map.fd = open(vars->map.path, O_RDONLY);
	vars->map.grid = malloc(vars->map.nb_l * sizeof(char *) + 1);
	vars->map.cell = malloc(vars->map.nb_l * sizeof(int *));
}

void	allocate_line(t_vars *vars, t_point *pos)
{
	vars->map.grid[pos->co_y] = malloc((vars->map.nb_c) * sizeof(char) + 1);
	vars->map.cell[pos->co_y] = malloc((vars->map.nb_c) * sizeof(int));
}

void	fill_line_cell(char *line, t_vars *vars, t_point *pos)
{
	vars->map.grid[pos->co_y][pos->co_x] = line[pos->co_x];
	vars->map.cell[pos->co_y][pos->co_x] = 0;
	pos->co_x++;
}