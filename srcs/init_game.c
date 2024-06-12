/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 04:57:30 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/12 12:19:42 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_vars *vars, char *av)
{
	vars->map.path = av;
	vars->elems.NB_COLLECTIBLES = 0;
	vars->elems.NB_START = 0;
	vars->elems.NB_EXIT = 0;
	vars->EXIT_FOUND = 0;
	vars->C_FOUND = 0;
	vars->WIN = 0;
	vars->start_p = (t_point){0, 0};
}
