/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:57:25 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/09 03:15:53 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber_map(char *map)
{
	const size_t	len = ft_strlen(map);

	if (map[len - 1] == 'r' && map[len - 2] == 'e' && map[len - 3] == 'b')
		return (1);
	return (0);
}

size_t	ft_linelen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	allocate_grid(t_vars *vars, t_point *pos)
{
	pos->co_x = 0;
	pos->co_y = 0;
	vars->map.fd = open(vars->map.path, O_RDONLY);
	vars->map.grid = malloc(vars->map.nb_l * sizeof(char *));
}

void	allocate_line(t_vars *vars, t_point *pos)
{
	vars->map.grid[pos->co_y] = malloc((vars->map.nb_c - 1) * sizeof(char));
}

