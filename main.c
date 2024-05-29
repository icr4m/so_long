/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:31:43 by ijaber            #+#    #+#             */
/*   Updated: 2024/05/29 09:05:00 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		ft_putstr_fd("Usage : ./so_long <map.ber> \n", 2);
	else if (ac > 2)
		ft_putstr_fd("Too many args... \n", 2);
	else if (ac == 2 && !check_ber_map(av[1]))
		ft_putstr_fd("Wrong File or Map Name. \n", 2);
	ft_parsing(av[1]);
	return (0);
}
