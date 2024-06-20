/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:31:43 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/21 01:55:38 by ijaber           ###   ########.fr       */
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
	printf("%s\n", av[1]);
	init_game(&vars, av[1]);
	map_parsing(&vars);
	fill_grid(&vars);
	check_wall(&vars);
	map_checker(&vars);
	find_map_error(&vars);
	path_finder(&vars, vars.player.start_p);
	is_win(&vars);
	new_window(&vars);
	load_sprite(&vars);
	draw_map(&vars);
	// Hooks
	mlx_hook(vars.win_ptr, KeyPress, KeyPressMask, &input_manager, &vars);
	mlx_loop(vars.mlx_ptr);
	free_all_image(&vars);
	free_grid(&vars);
	return (0);
}
