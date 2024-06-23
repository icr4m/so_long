/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:11:53 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/23 17:30:29 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars, t_point pos)
{
	vars->player.d = 1;
	if (pos.co_x < vars->map.nb_c && pos.co_y < vars->map.nb_l)
	{
		if (vars->map.grid[pos.co_y][pos.co_x] == COLLECT)
		{
			vars->elems.c_found++;
			vars->map.grid[pos.co_y][pos.co_x] = FLOOR;
			if (vars->elems.c_found == vars->elems.nb_collectibles)
				vars->elems.exit_unlock = 1;
			vars->player.co = pos;
		}
		else if (vars->map.grid[pos.co_y][pos.co_x] == EXIT
			&& vars->elems.exit_unlock == 1)
		{
			vars->elems.is_win = 1;
			vars->player.co = pos;
		}
		else if (vars->map.grid[pos.co_y][pos.co_x] != WALL)
			vars->player.co = pos;
	}
}

void	move_down(t_vars *vars, t_point pos)
{
	vars->player.d = 0;
	if (pos.co_x < vars->map.nb_c && pos.co_y < vars->map.nb_l)
	{
		if (vars->map.grid[pos.co_y][pos.co_x] == COLLECT)
		{
			vars->elems.c_found++;
			vars->map.grid[pos.co_y][pos.co_x] = FLOOR;
			if (vars->elems.c_found == vars->elems.nb_collectibles)
				vars->elems.exit_unlock = 1;
			vars->player.co = pos;
		}
		else if (vars->map.grid[pos.co_y][pos.co_x] == EXIT
			&& vars->elems.exit_unlock == 1)
		{
			vars->elems.is_win = 1;
			vars->player.co = pos;
		}
		else if (vars->map.grid[pos.co_y][pos.co_x] != WALL)
			vars->player.co = pos;
	}
}

void	move_right(t_vars *vars, t_point pos)
{
	vars->player.d = 1;
	if (pos.co_x < vars->map.nb_c && pos.co_y < vars->map.nb_l)
	{
		if (vars->map.grid[pos.co_y][pos.co_x] == COLLECT)
		{
			vars->elems.c_found++;
			vars->map.grid[pos.co_y][pos.co_x] = FLOOR;
			if (vars->elems.c_found == vars->elems.nb_collectibles)
				vars->elems.exit_unlock = 1;
			vars->player.co = pos;
		}
		else if (vars->map.grid[pos.co_y][pos.co_x] == EXIT
			&& vars->elems.exit_unlock == 1)
		{
			vars->elems.is_win = 1;
			vars->player.co = pos;
		}
		else if (vars->map.grid[pos.co_y][pos.co_x] != WALL)
			vars->player.co = pos;
	}
}

void	move_left(t_vars *vars, t_point pos)
{
	vars->player.d = 0;
	if (pos.co_x < vars->map.nb_c && pos.co_y < vars->map.nb_l)
	{
		if (vars->map.grid[pos.co_y][pos.co_x] == COLLECT)
		{
			vars->elems.c_found++;
			vars->map.grid[pos.co_y][pos.co_x] = FLOOR;
			if (vars->elems.c_found == vars->elems.nb_collectibles)
				vars->elems.exit_unlock = 1;
			vars->player.co = pos;
		}
		else if (vars->map.grid[pos.co_y][pos.co_x] == EXIT
			&& vars->elems.exit_unlock == 1)
		{
			vars->elems.is_win = 1;
			vars->player.co = pos;
		}
		else if (vars->map.grid[pos.co_y][pos.co_x] != WALL)
			vars->player.co = pos;
	}
}
