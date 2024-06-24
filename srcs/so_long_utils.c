/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:48:18 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/24 11:55:21 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(char *str, t_vars *vars)
{
	free_grid(vars);
	ft_printf(RED "Error: \n" WHITE);
	ft_printf("%s", str);
	exit(1);
}

void	error_arg(char *str, t_vars *vars)
{
	ft_printf(RED "Error: \n" WHITE);
	ft_printf("%s", str);
	exit(1);
}

int	input_manager(int keynb, t_vars *vars)
{
	if (keynb == ECHAP || keynb == CLOSE_ICON)
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
		move_left(vars, (t_point){vars->player.co.co_x - 1,
			vars->player.co.co_y});
	if (keynb == DOWN || keynb == DOWN2)
		move_down(vars, (t_point){vars->player.co.co_x, vars->player.co.co_y
			+ 1});
	return (0);
}

int	update_render(t_vars *vars)
{
	char	*tmp;

	if (vars->elems.is_win == 1)
		free_final(vars);
	draw_map(vars);
	draw_player(vars);
	tmp = ft_itoa(vars->player.nb_moves);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 42, 42, 16711884, tmp);
	free(tmp);
	usleep(65500);
	return (0);
}
