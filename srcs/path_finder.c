/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:38:14 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/23 17:33:54 by ijaber           ###   ########.fr       */
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
				vars->elems.nb_start++;
				vars->player.start_p = (t_point){x, y};
				vars->player.co = vars->player.start_p;
			}
			if (vars->map.grid[y][x] == EXIT)
				vars->elems.nb_exit++;
			if (vars->map.grid[y][x] == COLLECT)
				vars->elems.nb_collectibles++;
			x++;
		}
		y++;
	}
}

void	find_map_error(t_vars *vars)
{
	if (vars->elems.nb_exit < 1)
		error_map("No exit found.", vars);
	if (vars->elems.nb_exit > 1)
		error_map("Too much exit found.", vars);
	if (vars->elems.nb_start < 1)
		error_map("No start found.", vars);
	if (vars->elems.nb_start > 1)
		error_map("Too much start found.", vars);
	if (vars->elems.nb_collectibles <= 0)
		error_map("No collectibles found", vars);
}

void	path_finder(t_vars *vars, t_point pos)
{
	if (pos.co_x > vars->map.nb_c || pos.co_y > vars->map.nb_l || pos.co_x < 0
		|| pos.co_y < 0)
		return ;
	if (vars->map.grid[pos.co_y][pos.co_x] == WALL
		|| vars->map.cell[pos.co_y][pos.co_x] == 1)
		return ;
	vars->map.cell[pos.co_y][pos.co_x] = 1;
	if (vars->map.grid[pos.co_y][pos.co_x] == COLLECT)
		vars->elems.c_acces++;
	if (vars->map.grid[pos.co_y][pos.co_x] == EXIT)
		vars->elems.exit_found++;
	path_finder(vars, (t_point){pos.co_x + 1, pos.co_y});
	path_finder(vars, (t_point){pos.co_x - 1, pos.co_y});
	path_finder(vars, (t_point){pos.co_x, pos.co_y + 1});
	path_finder(vars, (t_point){pos.co_x, pos.co_y - 1});
}

void	path_checker(t_vars *vars)
{
	if (vars->elems.exit_found != 1)
		error_map("No path found", vars);
}
