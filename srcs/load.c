/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:37:47 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/16 16:54:36 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprite(t_vars *vars)
{
	vars->background.img = mlx_xpm_file_to_image(vars->windows.mlx_ptr,
			"assets/background.xpm", &vars->background.size.co_x,
			&vars->background.size.co_y);
	vars->collectibles.img = mlx_xpm_file_to_image(vars->windows.mlx_ptr,
			"assets/collectible.xpm", &vars->collectibles.size.co_x,
			&vars->collectibles.size.co_y);
	vars->exit.img = mlx_xpm_file_to_image(vars->windows.mlx_ptr,
			"assets/exit.xpm", &vars->exit.size.co_x, &vars->exit.size.co_y);
}
