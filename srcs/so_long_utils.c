/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:48:18 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/20 18:20:41 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(char *str)
{
	ft_printf(Red "Error: " White);
	ft_printf("%s \n", str);
	exit(1);
}

int	input_manager(int keynb, t_vars *vars)
{
	if (keynb == ECHAP)
	{
		free_all_image(vars);
		free_grid(vars);
		mlx_destroy_display(vars->mlx_ptr);
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		free(vars->mlx_ptr);
		exit(0);
		return (0);
	}
	if (keynb == UP || keynb == UP2)
		printf("start position :%ld %ld\n", vars->player.start_p.co_y,
			vars->player.start_p.co_x);
	if (keynb == RIGHT || keynb == RIGHT2)
		printf("start position :%ld %ld\n", vars->player.start_p.co_y,
			vars->player.start_p.co_x);
	if (keynb == LEFT || keynb == LEFT2)
		printf("start position :%ld %ld\n", vars->player.start_p.co_y,
			vars->player.start_p.co_x);
	if (keynb == DOWN || keynb == DOWN2)
		printf("start position :%ld %ld\n", vars->player.start_p.co_y,
			vars->player.start_p.co_x);
	return (0);
}
