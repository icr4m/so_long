/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:48:18 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/21 03:38:52 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(char *str)
{
	ft_printf(Red "Error: " White);
	ft_printf("%s \n", str);
	exit(1);
}

void	update_player(t_vars *vars)
{
	vars->player.co = vars->player.start_p;
}

int	input_manager(int keynb, t_vars *vars)
{
	if (keynb == ECHAP)
	{
		free_final(vars);
		return (0);
	}
	if (keynb == UP || keynb == UP2)
		move_up(vars, (t_point){vars->player.co.co_x, vars->player.co.co_y
			- 1});
	if (keynb == RIGHT || keynb == RIGHT2)
		move_right(vars, (t_point){vars->player.co.co_x + 1,
			vars->player.co.co_y});
	if (keynb == LEFT || keynb == LEFT2)
		move_up(vars, (t_point){vars->player.co.co_x - 1,
			vars->player.co.co_y});
	if (keynb == DOWN || keynb == DOWN2)
		move_up(vars, (t_point){vars->player.co.co_x, vars->player.co.co_y
			+ 1});
	return (0);
}

int	update_render(t_vars *vars)
{
	if (vars->elems.IS_WIN == 1)
		error_map("masterclass");
	draw_map(vars);
	draw_player(vars);
	return (0);
}