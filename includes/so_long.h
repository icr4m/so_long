/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:52:28 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/23 21:24:35 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WHITE "\033[0;37m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"

# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define COLLECT 'C'

# define PLAYER_XPM_ERROR "player.xpm fail to load"
# define GROUND_XPM_ERROR "ground.xpm fail to load"
# define WALL_XPM_ERROR "wall.xpm fail to load"
# define COLLECT_XPM_ERROR "collectibles.xpm fail to load"
# define EXIT_XPM_ERROR "exit.xpm fail to load"

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

// Functions

// DISPLAY
void				draw_map(t_vars *vars);
void				put_to_image(t_vars *vars, t_point s, char type);
void				draw_player(t_vars *vars);

// FREE
void				free_grid(t_vars *vars);
void				free_all_image(t_vars *vars);
void				free_final(t_vars *vars);
int					close_windows(t_vars *vars);

// INIT GAME
void				init_game(t_vars *vars, char *av);
void				new_window(t_vars *vars);
void				start_game(t_vars *vars, char *av);

// ITOA
static unsigned int	get_abs(int n);
static size_t		nb_len(int nb);
static void			fill_number(char *src, int nb, unsigned int len);
char				*ft_itoa(int n);

// LOAD
void				load_sprite(t_vars *vars);
void				load_player_sprites(t_vars *vars);

// PARSING UTILS
int					check_ber_map(char *map);
size_t				ft_linelen(char *s);
void				allocate_grid_cell(t_vars *vars, t_point *pos);
void				allocate_line(t_vars *vars, t_point *pos);
void				fill_line_cell(char *line, t_vars *vars, t_point *pos);

// MAP PARSING
int					map_parsing(t_vars *vars);
void				fill_grid(t_vars *vars);
void				check_wall(t_vars *vars);

// PATH FINDER
void				map_checker(t_vars *vars);
void				find_map_error(t_vars *vars);
void				path_finder(t_vars *vars, t_point pos);
void				path_checker(t_vars *vars);

// PLAYER MOVE
void				move_up(t_vars *vars, t_point pos);
void				move_down(t_vars *vars, t_point pos);
void				move_right(t_vars *vars, t_point pos);
void				move_left(t_vars *vars, t_point pos);

// SO LONG UTILS
void				error_map(char *str, t_vars *vars);
void				error_arg(char *str, t_vars *vars);
int					input_manager(int keynb, t_vars *vars);
int					update_render(t_vars *vars);

#endif