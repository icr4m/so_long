/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:52:28 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/17 17:46:42 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define White "\033[0;37m"
# define Green "\033[0;32m"
# define Red "\033[0;31m"
# define Purple "\033[0;35m"

# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define COLLECT 'C'

# ifndef SIZE
#  define SIZE 64
# endif

# include "ft_printf.h"
# include "get_next_line.h"
# include "struct.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// functions
void	init_game(t_vars *vars, char *av);
void	new_window(t_vars *vars);
int		close_window(int keynb, t_vars *vars);
int		key_moves(int keynb, t_vars *vars);

int		check_ber_map(char *map);
size_t	ft_linelen(char *s);
void	error_map(char *str);
void	allocate_grid_cell(t_vars *vars, t_point *pos);
void	allocate_line(t_vars *vars, t_point *pos);
void	fill_line_cell(char *line, t_vars *vars, t_point *pos);

int		map_parsing(t_vars *vars);
void	fill_grid(t_vars *vars);
void	check_wall(t_vars *vars);

void	map_checker(t_vars *vars);
void	find_map_error(t_vars *vars);
void	path_finder(t_vars *vars, t_point pos);
void	is_win(t_vars *vars);

void	load_sprite(t_vars *vars);

void	draw_map(t_vars *vars);
void	put_to_image(t_vars *vars, t_point s, char type);

#endif