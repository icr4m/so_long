/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:52:28 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/10 16:43:47 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define COLLECT 'C'

# include "ft_printf.h"
# include "get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// typedef struct
typedef struct s_point
{
	size_t	co_x;
	size_t	co_y;
}			t_point;

typedef struct s_cell
{
	char	type;
	int		value;
}			t_cell;

typedef struct s_map
{
	char	*path;
	int		fd;
	char	**grid;
	t_cell	**cell;
	size_t	nb_c;
	size_t	nb_l;
}			t_map;

typedef struct s_vars
{
	t_map	map;
}			t_vars;

// functions
void		init_game(t_vars *vars, char *av);
int			check_ber_map(char *map);
size_t		ft_linelen(char *s);
void		error_map(char *str);
int			map_parsing(t_vars *vars);
void		fill_grid(t_vars *vars);
void		allocate_grid_cell(t_vars *vars, t_point *pos);
void		allocate_line(t_vars *vars, t_point *pos);
void		check_wall(t_vars *vars);
void		check_P_E(t_vars *vars);
void		fill_line_cell(char *line, t_vars *vars, t_point *pos);

#endif