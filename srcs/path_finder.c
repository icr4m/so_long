/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:38:14 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/12 11:57:29 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checker(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < vars->map.nb_l)
	{
		j = 0;
		while (j < vars->map.nb_c)
		{
			if (vars->map.grid[i][j] == START)
				vars->elems.NB_START++;
			if (vars->map.grid[i][j] == EXIT)
				vars->elems.NB_EXIT++;
			if (vars->map.grid[i][j] == COLLECT)
				vars->elems.NB_COLLECTIBLES++;
			j++;
		}
		i++;
	}
}

void	find_map_error(t_vars *vars)
{
	if (vars->elems.NB_EXIT < 1)
		error_map("No exit found.");
	if (vars->elems.NB_EXIT > 1)
		error_map("Too much exit found.");
	if (vars->elems.NB_START < 1)
		error_map("No start found.");
	if (vars->elems.NB_START > 1)
		error_map("Too much start found.");
}

void	path_finder(t_vars *vars, t_point pos)
{
	if (vars->EXIT_FOUND == 1 && vars->C_FOUND == vars->elems.NB_COLLECTIBLES)
		vars->WIN = 1;
	vars->map.cell = 1;
	if (vars->map.grid[pos.co_x][pos.co_y] == COLLECT)
		vars->elems.NB_COLLECTIBLES++;
	if (vars->map.grid[pos.co_x][pos.co_y] == EXIT)
		vars->EXIT_FOUND++;
	path_finder(vars, (t_point){pos.co_x + 1, pos.co_y});
	path_finder(vars, (t_point){pos.co_x - 1, pos.co_y});
	path_finder(vars, (t_point){pos.co_x, pos.co_y + 1});
	path_finder(vars, (t_point){pos.co_x, pos.co_y - 1});
}