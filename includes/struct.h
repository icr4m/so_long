/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:47:19 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/21 04:53:45 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_key
{
	UP = 65362,
	UP2 = 119,
	RIGHT = 65363,
	RIGHT2 = 100,
	LEFT = 65361,
	LEFT2 = 97,
	DOWN = 65364,
	DOWN2 = 115,
	ECHAP = 65307
}					t_key;

// typedef struct
typedef struct s_point
{
	size_t			co_x;
	size_t			co_y;
}					t_point;

typedef struct s_cell
{
	char			type;
	int				value;
}					t_cell;

typedef struct s_sprite
{
	int				s_x;
	int				s_y;
	void			*img;
}					t_sprite;

typedef struct s_player
{
	t_point			start_p;
	t_point			co;
	int				d;
}					t_player;

typedef struct s_sprite_player
{
	t_sprite		UP1;
	t_sprite		UP2;
	t_sprite		DOWN1;
	t_sprite		DOWN2;
}					t_sprite_player;

typedef struct s_map
{
	char			*path;
	int				fd;
	char			**grid;
	t_cell			**cell;
	size_t			nb_c;
	size_t			nb_l;
}					t_map;

typedef struct s_elems
{
	size_t			NB_EXIT;
	size_t			NB_START;
	size_t			NB_COLLECTIBLES;
	size_t			EXIT_FOUND;
	size_t			C_FOUND;
	size_t			IS_WIN;
	size_t			C_acces;
	size_t			exit_unlock;
}					t_elems;

typedef struct s_vars
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_map			map;
	t_elems			elems;
	t_sprite		wall;
	t_sprite		background;
	t_sprite		exit;
	t_sprite		collectibles;
	t_sprite_player	s_player;
	t_player		player;
}					t_vars;

#endif