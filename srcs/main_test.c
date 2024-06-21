/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:31:43 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/21 05:52:32 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac < 2)
		error_map("Usage : ./so_long <map.ber>");
	if (ac > 2)
		error_map("Too many args..");
	if (ac == 2 && !check_ber_map(av[1]))
		error_map("Wrong File or Map Name.");
	init_game(&vars, av[1]);
	map_parsing(&vars);
	fill_grid(&vars);
	check_wall(&vars);
	map_checker(&vars);
	find_map_error(&vars);
	path_finder(&vars, vars.player.start_p);
	update_player(&vars);
	new_window(&vars);
	load_sprite(&vars);
	draw_map(&vars);
	// Hooks
	mlx_hook(vars.win_ptr, KeyPress, KeyPressMask, &input_manager, &vars);
	mlx_hook(vars.win_ptr, DestroyNotify, StructureNotifyMask, &close_windows,
		&vars);
	mlx_loop_hook(vars.mlx_ptr, update_render, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
