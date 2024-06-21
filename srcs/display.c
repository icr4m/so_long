/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:34:13 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/21 03:22:40 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_vars *vars)
{
	t_point	s;

	s.co_y = 0;
	while (s.co_y < vars->map.nb_l * SIZE)
	{
		s.co_x = 0;
		while (s.co_x < vars->map.nb_c * SIZE)
		{
			if (vars->map.grid[s.co_y / SIZE][s.co_x / SIZE] == WALL)
				put_to_image(vars, s, WALL);
			if (vars->map.grid[s.co_y / SIZE][s.co_x / SIZE] == EXIT)
				put_to_image(vars, s, EXIT);
			if (vars->map.grid[s.co_y / SIZE][s.co_x / SIZE] == COLLECT)
				put_to_image(vars, s, COLLECT);
			if (vars->map.grid[s.co_y / SIZE][s.co_x / SIZE] == FLOOR)
				put_to_image(vars, s, FLOOR);
			if (vars->map.grid[s.co_y / SIZE][s.co_x / SIZE] == START)
				put_to_image(vars, s, FLOOR);
			s.co_x += SIZE;
		}
		s.co_y += SIZE;
	}
}

void	put_to_image(t_vars *vars, t_point s, char type)
{
	if (type == WALL)
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->wall.img,
			s.co_x, s.co_y);
	if (type == EXIT)
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->exit.img,
			s.co_x, s.co_y);
	if (type == COLLECT)
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->collectibles.img, s.co_x, s.co_y);
	if (type == FLOOR)
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->background.img, s.co_x, s.co_y);
}

void	draw_player(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->s_player.DOWN1.img, vars->player.co.co_x * SIZE,
		vars->player.co.co_y * SIZE);
}
