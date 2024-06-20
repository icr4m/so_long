/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:48:18 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/20 17:18:00 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(char *str)
{
	ft_printf(Red "Error: " White);
	ft_printf("%s \n", str);
	exit(1);
}

int	key_moves(int keynb, t_vars *vars)
{
	if (keynb == UP || keynb == UP2)
		printf("start position :%ld %ld\n", vars->player.start_p.co_x,
			vars->player.start_p.co_y);
	if (keynb == RIGHT || keynb == RIGHT2)
		printf("start position :%ld %ld\n", vars->player.start_p.co_x,
			vars->player.start_p.co_y);
	if (keynb == LEFT || keynb == LEFT2)
		printf("start position :%ld %ld\n", vars->player.start_p.co_x,
			vars->player.start_p.co_y);
	if (keynb == DOWN || keynb == DOWN2)
		printf("start position :%ld %ld\n", vars->player.start_p.co_x,
			vars->player.start_p.co_y);
	return (0);
}

// void player_move(t_vars *vars, t_point pos)
// {

// }
