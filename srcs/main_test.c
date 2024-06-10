/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:31:43 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/10 20:02:48 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define White "\033[0;37m"
#define Green "\033[0;32m"
#define Red "\033[0;31m"
#define Purple "\033[0;35m"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac < 2)
		error_map("Usage : ./so_long <map.ber>");
	if (ac > 2)
		error_map("Too many args..");
	if (ac == 2 && !check_ber_map(av[1]))
		error_map("Wrong File or Map Name.");
	ft_printf("%s\n", av[1]);
	init_game(&vars, av[1]);
	map_parsing(&vars);
	fill_grid(&vars);
	check_wall(&vars);
	map_checker(&vars);
	ft_printf(Red "C =%d\n", vars.elems.NB_COLLECTIBLES);
	ft_printf(Green "E =%d\n", vars.elems.NB_EXIT);
	ft_printf(Purple "P =%d\n", vars.elems.NB_START);
	ft_printf(White);
	ft_printf("good\n");
	return (0);
}
