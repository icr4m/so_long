/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:03:59 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/20 18:10:40 by ijaber           ###   ########.fr       */
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
		vars->map.cell[i] == NULL;
		vars->map.grid[i] == NULL;
		i++;
	}
	free(vars->map.cell);
	free(vars->map.grid);
	vars->map.cell = NULL;
	vars->map.grid = NULL;
}

void	free_all_image(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_ptr, vars->wall.img);
	mlx_destroy_image(vars->mlx_ptr, vars->background.img);
	mlx_destroy_image(vars->mlx_ptr, vars->exit.img);
	mlx_destroy_image(vars->mlx_ptr, vars->collectibles.img);
}
