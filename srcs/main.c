/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:31:43 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/05 16:33:20 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	map.path = av[1];
	if (ac < 2)
		ft_printf("Usage : ./so_long <map.ber> \n");
	if (ac > 2)
		ft_printf("Too many args.. \n");
	if (ac == 2 && !check_ber_map(map.path))
		ft_printf("Wrong File or Map Name. \n", 2);
	ft_is_rectangular(map);
	return (0);
}
