/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 04:57:30 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/17 17:55:21 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_vars *vars, char *av)
{
	vars->map.path = av;
	vars->elems.NB_COLLECTIBLES = 0;
	vars->elems.NB_START = 0;
	vars->elems.NB_EXIT = 0;
	vars->EXIT_FOUND = 0;
	vars->C_FOUND = 0;
	vars->WIN = 0;
	vars->player.start_p = (t_point){0, 0};
}

void	new_window(t_vars *vars)
{
	vars->windows.mlx_ptr = mlx_init();
	vars->windows.win_ptr = mlx_new_window(vars->windows.mlx_ptr, vars->map.nb_l
			* SIZE, vars->map.nb_c * SIZE, "Squirtle Lounge");
}

int	key_moves(int keynb, t_vars *vars)
{
	printf("Key press :%d\n", keynb);
	return (1);
}

int	close_window(int keynb, t_vars *vars)
{
	if (keynb == 65307)
	{
		mlx_destroy_display(vars->windows.mlx_ptr);
		mlx_destroy_window(vars->windows.mlx_ptr, vars->windows.win_ptr);
		free(vars->windows.mlx_ptr);
		exit(0);
		return (0);
	}
	else
		return (1);
}
