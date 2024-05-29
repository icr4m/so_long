/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:31:43 by ijaber            #+#    #+#             */
/*   Updated: 2024/05/29 15:22:39 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		ft_printf("Usage : ./so_long <map.ber> \n");
	else if (ac > 2)
		ft_printf("Too many args... \n");
	else if (ac == 2 && !check_ber_map(av[1]))
		ft_printf("Wrong File or Map Name. \n", 2);
	ft_parsing(av[1]);
	return (0);
}
