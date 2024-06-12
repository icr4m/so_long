/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:10:38 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/12 17:09:26 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	new_window(t_vars *vars)
{
	vars->windows.mlx_ptr = mlx_init();
	if (!vars->windows.mlx_ptr)
		return (1);
	vars->windows.win_ptr = mlx_new_window(vars->windows.mlx_ptr, 2200, 2120,
			"SO LONG");
	if (!vars->windows.win_ptr)
		return (0);
	mlx_loop(vars->windows.mlx_ptr);
}
