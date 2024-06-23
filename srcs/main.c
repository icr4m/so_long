/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:31:43 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/23 17:34:10 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac < 2)
		error_arg("Usage : ./so_long <map.ber>", &vars);
	if (ac > 2)
		error_arg("Too many args..", &vars);
	if (ac == 2 && !check_ber_map(av[1]))
		error_arg("Wrong File or Map Name.", &vars);
	start_game(&vars, av[1]);
	mlx_loop_hook(vars.mlx_ptr, update_render, &vars);
	mlx_hook(vars.win_ptr, KeyPress, KeyPressMask, &input_manager, &vars);
	mlx_hook(vars.win_ptr, DestroyNotify, StructureNotifyMask, &close_windows,
		&vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
