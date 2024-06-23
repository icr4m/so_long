/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:47:19 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/23 20:07:20 by ijaber           ###   ########.fr       */
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
	ECHAP = 65307,
	CLOSE_ICON = 17,
}					t_key;

// typedef struct
typedef struct s_point
{
	size_t			co_x;
	size_t			co_y;
}					t_point;

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
	int				nb_moves;
}					t_player;

typedef struct s_sprite_player
{
	t_sprite		up1;
	t_sprite		up2;
	t_sprite		down1;
	t_sprite		down2;
}					t_sprite_player;

typedef struct s_map
{
	char			*path;
	int				fd;
	char			**grid;
	int				**cell;
	size_t			nb_c;
	size_t			nb_l;
}					t_map;

typedef struct s_elems
{
	size_t			nb_exit;
	size_t			nb_start;
	size_t			nb_collectibles;
	size_t			exit_found;
	size_t			c_found;
	size_t			is_win;
	size_t			c_acces;
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