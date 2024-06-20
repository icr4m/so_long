/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:37:47 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/20 17:26:32 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprite(t_vars *vars)
{
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/wall3.xpm", &vars->wall.s_x, &vars->wall.s_y);
	vars->background.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/ground.xpm", &vars->background.s_x, &vars->background.s_y);
	vars->collectibles.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/collectibles.xpm", &vars->collectibles.s_x,
			&vars->collectibles.s_y);
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/exit.xpm", &vars->exit.s_x, &vars->exit.s_y);
	// vars->herbe.img = mlx_xpm_file_to_image(vars->windows.mlx_ptr,
	// 		"assets/Hautes_herbes_DP.xpm", &vars->herbe.s_x, &vars->herbe.s_y);
}
