/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:52:28 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/09 00:16:06 by ijaber           ###   ########.fr       */
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

// typedef struct
typedef struct s_point
{
	size_t	co_x;
	size_t	co_y;
}			t_point;

typedef struct s_map
{
	char	*path;
	int		fd;
	size_t	nb_c;
	size_t	nb_l;
	t_point	co;
}			t_map;

typedef struct s_vars
{
	t_map	map;
}			t_vars;

// functions
void		ft_is_rectangular(t_map map);
int			check_ber_map(char *map);
size_t		ft_linelen(char *s);
void		map_error(char *str);

#endif