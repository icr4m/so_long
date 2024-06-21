/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 04:57:30 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/21 06:05:49 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_vars *vars, char *av)
{
	vars->map.path = av;
	vars->elems.C_FOUND = 0;
	vars->elems.IS_WIN = 0;
	vars->elems.EXIT_FOUND = 0;
	vars->elems.NB_COLLECTIBLES = 0;
	vars->elems.NB_START = 0;
	vars->elems.NB_EXIT = 0;
	vars->elems.C_acces = 0;
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
