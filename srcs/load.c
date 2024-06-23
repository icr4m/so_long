/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:37:47 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/23 22:32:49 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprite(t_vars *vars)
{
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx_ptr, "assets/wall3.xpm",
			&vars->wall.s_x, &vars->wall.s_y);
	if (!vars->wall.img)
		free_sprite(WALL_XPM_ERROR, vars, 0);
	vars->background.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/ground.xpm", &vars->background.s_x, &vars->background.s_y);
	if (!vars->background.img)
		free_sprite(GROUND_XPM_ERROR, vars, 1);
	vars->collectibles.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/collectibles.xpm", &vars->collectibles.s_x,
			&vars->collectibles.s_y);
	if (!vars->collectibles.img)
		free_sprite(COLLECT_XPM_ERROR, vars, 2);
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx_ptr, "assets/exit.xpm",
			&vars->exit.s_x, &vars->exit.s_y);
	if (!vars->exit.img)
		free_sprite(EXIT_XPM_ERROR, vars, 3);
}

void	load_player_sprites(t_vars *vars)
{
	vars->s_player.up1.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/caraspriteD1.xpm", &vars->s_player.up1.s_x,
			&vars->s_player.up1.s_y);
	if (!vars->s_player.up1.img)
		free_sprite(PLAYER_XPM_ERROR, vars, 4);
	vars->s_player.up2.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/caraspriteD2.xpm", &vars->s_player.up2.s_x,
			&vars->s_player.up2.s_y);
	if (!vars->s_player.up2.img)
		free_sprite(PLAYER_XPM_ERROR, vars, 5);
	vars->s_player.down1.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/spritecara1.xpm", &vars->s_player.down1.s_x,
			&vars->s_player.down1.s_y);
	if (!vars->s_player.down1.img)
		free_sprite(PLAYER_XPM_ERROR, vars, 6);
	vars->s_player.down2.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/spritecara2.xpm", &vars->s_player.down2.s_x,
			&vars->s_player.down2.s_y);
	if (!vars->s_player.down2.img)
		free_sprite(PLAYER_XPM_ERROR, vars, 7);
}
