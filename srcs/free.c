/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:03:59 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/23 22:31:27 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (i < vars->map.nb_l)
	{
		free(vars->map.cell[i]);
		free(vars->map.grid[i]);
		i++;
	}
	free(vars->map.cell);
	free(vars->map.grid);
}

void	free_all_image(t_vars *vars)
{
	if (vars->wall.img)
		mlx_destroy_image(vars->mlx_ptr, vars->wall.img);
	if (vars->background.img)
		mlx_destroy_image(vars->mlx_ptr, vars->background.img);
	if (vars->collectibles.img)
		mlx_destroy_image(vars->mlx_ptr, vars->collectibles.img);
	if (vars->exit.img)
		mlx_destroy_image(vars->mlx_ptr, vars->exit.img);
	if (vars->s_player.down1.img)
		mlx_destroy_image(vars->mlx_ptr, vars->s_player.down1.img);
	if (vars->s_player.down2.img)
		mlx_destroy_image(vars->mlx_ptr, vars->s_player.down2.img);
	if (vars->s_player.up1.img)
		mlx_destroy_image(vars->mlx_ptr, vars->s_player.up1.img);
	if (vars->s_player.up2.img)
		mlx_destroy_image(vars->mlx_ptr, vars->s_player.up2.img);
}

void	free_final(t_vars *vars)
{
	if (vars->win_ptr)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	free_all_image(vars);
	free_grid(vars);
	if (vars->mlx_ptr)
		mlx_destroy_display(vars->mlx_ptr);
	if (vars->mlx_ptr)
		free(vars->mlx_ptr);
	exit(0);
}

int	close_windows(t_vars *vars)
{
	free_final(vars);
	return (0);
}

void	free_sprite(char *str, t_vars *vars, int nb)
{
	if (nb >= 1)
		mlx_destroy_image(vars->mlx_ptr, vars->wall.img);
	if (nb >= 2)
		mlx_destroy_image(vars->mlx_ptr, vars->background.img);
	if (nb >= 3)
		mlx_destroy_image(vars->mlx_ptr, vars->collectibles.img);
	if (nb >= 4)
		mlx_destroy_image(vars->mlx_ptr, vars->exit.img);
	if (nb >= 5)
		mlx_destroy_image(vars->mlx_ptr, vars->s_player.up1.img);
	if (nb >= 6)
		mlx_destroy_image(vars->mlx_ptr, vars->s_player.up2.img);
	if (nb >= 7)
		mlx_destroy_image(vars->mlx_ptr, vars->s_player.down1.img);
	if (vars->win_ptr)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	if (vars->mlx_ptr)
		mlx_destroy_display(vars->mlx_ptr);
	if (vars->mlx_ptr)
		free(vars->mlx_ptr);
	error_map(str, vars);
}
