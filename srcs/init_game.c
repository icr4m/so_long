/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 04:57:30 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/23 17:27:30 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_vars *vars, char *av)
{
	vars->map.path = av;
	vars->elems.c_found = 0;
	vars->elems.is_win = 0;
	vars->elems.exit_found = 0;
	vars->elems.nb_collectibles = 0;
	vars->elems.nb_start = 0;
	vars->elems.nb_exit = 0;
	vars->elems.c_acces = 0;
	vars->elems.exit_unlock = 0;
	vars->player.start_p = (t_point){0, 0};
	vars->player.d = 0;
}

void	new_window(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, vars->map.nb_c * SIZE,
			vars->map.nb_l * SIZE, "Squirtle Lounge");
}

void	start_game(t_vars *vars, char *av)
{
	init_game(vars, av);
	map_parsing(vars);
	fill_grid(vars);
	check_wall(vars);
	map_checker(vars);
	find_map_error(vars);
	path_finder(vars, vars->player.start_p);
	path_checker(vars);
	new_window(vars);
	load_sprite(vars);
}
