/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:37:47 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/23 17:28:32 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprite(t_vars *vars)
{
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx_ptr, "assets/wall3.xpm",
			&vars->wall.s_x, &vars->wall.s_y);
	vars->background.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/ground.xpm", &vars->background.s_x, &vars->background.s_y);
	vars->collectibles.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/collectibles.xpm", &vars->collectibles.s_x,
			&vars->collectibles.s_y);
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx_ptr, "assets/exit.xpm",
			&vars->exit.s_x, &vars->exit.s_y);
	vars->s_player.up1.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/caraspriteD1.xpm", &vars->s_player.up1.s_x,
			&vars->s_player.up1.s_y);
	vars->s_player.up2.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/caraspriteD2.xpm", &vars->s_player.up2.s_x,
			&vars->s_player.up2.s_y);
	vars->s_player.down1.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/spritecara1.xpm", &vars->s_player.down1.s_x,
			&vars->s_player.down1.s_y);
	vars->s_player.down2.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/spritecara2.xpm", &vars->s_player.down2.s_x,
			&vars->s_player.down2.s_y);
}
