/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:34:13 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/16 17:17:25 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_vars *vars)
{
	t_point	s;

	s.co_x = 0;
	while (s.co_x < vars->map.nb_l * SIZE)
	{
		s.co_y = 0;
		while (s.co_y < vars->map.nb_c * SIZE)
		{
			if (vars->map.grid[s.co_x / SIZE][s.co_y / SIZE] == WALL)
				ft_put_to_image(vars, s, WALL);
			if (vars->map.grid[s.co_x / SIZE][s.co_y / SIZE] == EXIT)
				ft_put_to_image(vars, s, EXIT);
			if (vars->map.grid[s.co_x / SIZE][s.co_y / SIZE] == COLLECT)
				ft_put_to_image(vars, s, COLLECT);
			if (vars->map.grid[s.co_x / SIZE][s.co_y / SIZE] == FLOOR)
				ft_put_to_image(vars, s, FLOOR);
			s.co_y += SIZE;
		}
		s.co_x += SIZE;
	}
}

void	ft_put_to_image(t_vars *vars, t_point pos, char type)
{
	if (type == WALL)
		mlx_put_image_to_window(vars->windows.mlx_ptr, vars->windows.win_ptr,
			vars->wall.img, vars->wall.size.co_x, vars->wall.size.co_y);
	if (type == EXIT)
		mlx_put_image_to_window(vars->windows.mlx_ptr, vars->windows.win_ptr,
			vars->exit.img, vars->exit.size.co_x, vars->exit.size.co_y);
	if (type == COLLECT)
		mlx_put_image_to_window(vars->windows.mlx_ptr, vars->windows.win_ptr,
			vars->collectibles.img, vars->collectibles.size.co_x,
			vars->collectibles.size.co_y);
	if (type == FLOOR)
		mlx_put_image_to_window(vars->windows.mlx_ptr, vars->windows.win_ptr,
			vars->background.img, vars->background.size.co_x,
			vars->background.size.co_y);
}
