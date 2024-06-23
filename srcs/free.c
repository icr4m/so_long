/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:03:59 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/23 17:39:09 by ijaber           ###   ########.fr       */
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
	if (vars->wall.img != NULL)
		mlx_destroy_image(vars->mlx_ptr, vars->wall.img);
	if (vars->background.img != NULL)
		mlx_destroy_image(vars->mlx_ptr, vars->background.img);
	if (vars->exit.img != NULL)
		mlx_destroy_image(vars->mlx_ptr, vars->exit.img);
	if (vars->collectibles.img != NULL)
		mlx_destroy_image(vars->mlx_ptr, vars->collectibles.img);
	if (vars->s_player.down1.img != NULL)
		mlx_destroy_image(vars->mlx_ptr, vars->s_player.down1.img);
	if (vars->s_player.down2.img != NULL)
		mlx_destroy_image(vars->mlx_ptr, vars->s_player.down2.img);
	if (vars->s_player.up1.img != NULL)
		mlx_destroy_image(vars->mlx_ptr, vars->s_player.up1.img);
	if (vars->s_player.up2.img != NULL)
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
