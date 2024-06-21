/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:38:14 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/21 03:31:17 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checker(t_vars *vars)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < vars->map.nb_l)
	{
		x = 0;
		while (x < vars->map.nb_c)
		{
			if (vars->map.grid[y][x] == START)
			{
				vars->elems.NB_START++;
				vars->player.start_p = (t_point){x, y};
			}
			if (vars->map.grid[y][x] == EXIT)
				vars->elems.NB_EXIT++;
			if (vars->map.grid[y][x] == COLLECT)
				vars->elems.NB_COLLECTIBLES++;
			x++;
		}
		y++;
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
	if (vars->elems.NB_COLLECTIBLES <= 0)
		error_map("No collectibles found");
}

void	path_finder(t_vars *vars, t_point pos)
{
	if (pos.co_x > vars->map.nb_c || pos.co_y > vars->map.nb_l || pos.co_x < 0
		|| pos.co_y < 0)
		return ;
	if (vars->map.grid[pos.co_y][pos.co_x] == WALL
		|| vars->map.cell[pos.co_y][pos.co_x].value == 1)
		return ;
	vars->map.cell[pos.co_y][pos.co_x].value = 1;
	if (vars->map.grid[pos.co_y][pos.co_x] == COLLECT)
		vars->elems.C_acces++;
	if (vars->map.grid[pos.co_y][pos.co_x] == EXIT)
		vars->elems.EXIT_FOUND++;
	path_finder(vars, (t_point){pos.co_x + 1, pos.co_y});
	path_finder(vars, (t_point){pos.co_x - 1, pos.co_y});
	path_finder(vars, (t_point){pos.co_x, pos.co_y + 1});
	path_finder(vars, (t_point){pos.co_x, pos.co_y - 1});
}
