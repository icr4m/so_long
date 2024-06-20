/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:34:13 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/20 17:25:39 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_vars *vars)
{
	t_point	s;

	s.co_x = 0;
	while (s.co_x < vars->map.nb_l * SIZE)
	{
		s.co_y = 0;
		while (s.co_y < vars->map.nb_c * SIZE)
		{
			if (vars->map.grid[s.co_x / SIZE][s.co_y / SIZE] == WALL)
				put_to_image(vars, s, WALL);
			if (vars->map.grid[s.co_x / SIZE][s.co_y / SIZE] == EXIT)
				put_to_image(vars, s, EXIT);
			if (vars->map.grid[s.co_x / SIZE][s.co_y / SIZE] == COLLECT)
				put_to_image(vars, s, COLLECT);
			if (vars->map.grid[s.co_x / SIZE][s.co_y / SIZE] == FLOOR)
				put_to_image(vars, s, FLOOR);
			if (vars->map.grid[s.co_x / SIZE][s.co_y / SIZE] == START)
				put_to_image(vars, s, FLOOR);
			s.co_y += SIZE;
		}
		s.co_x += SIZE;
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
