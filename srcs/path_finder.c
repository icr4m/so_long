/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:38:14 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/10 19:57:06 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checker(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < vars->map.nb_l)
	{
		j = 0;
		while (j < vars->map.nb_c)
		{
			if (vars->map.grid[i][j] == START)
				vars->elems.NB_START++;
			if (vars->map.grid[i][j] == EXIT)
				vars->elems.NB_EXIT++;
			if (vars->map.grid[i][j] == COLLECT)
				vars->elems.NB_COLLECTIBLES++;
			j++;
		}
		i++;
	}
}
