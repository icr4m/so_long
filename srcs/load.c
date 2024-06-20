/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:37:47 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/21 00:20:51 by ijaber           ###   ########.fr       */
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
	vars->s_player.UP1.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/carapuceD1.xpm", &vars->s_player.UP1.s_x,
			&vars->s_player.UP1.s_y);
	vars->s_player.UP2.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/carapuceD2.xpm", &vars->s_player.UP2.s_x,
			&vars->s_player.UP2.s_y);
	vars->s_player.DOWN1.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/spritecara1.xpm", &vars->s_player.DOWN1.s_x,
			&vars->s_player.DOWN1.s_y);
	vars->s_player.DOWN2.img = mlx_xpm_file_to_image(vars->mlx_ptr,
			"assets/spritecara2.xpm", &vars->s_player.DOWN2.s_x,
			&vars->s_player.DOWN2.s_y);
}

void	player_animation(t_animation *animation)
{
	if (animation->current == animation->frame_1)
		animation->current = animation->frame_2;
	if (animation->current == animation->frame_2)
		animation->current = animation->frame_1;
}

void	load_anim(t_vars *vars)
{
	vars->anim_D.current = vars->s_player.DOWN1.img;
	vars->anim_D.frame_1 = vars->s_player.DOWN1.img;
	vars->anim_D.frame_2 = vars->s_player.DOWN2.img;
	vars->anim_U.current = vars->s_player.UP1.img;
	vars->anim_U.frame_1 = vars->s_player.UP1.img;
	vars->anim_U.frame_2 = vars->s_player.UP1.img;
}
