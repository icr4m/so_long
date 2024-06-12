/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:47:19 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/12 17:08:44 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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

typedef struct s_elems
{
	size_t	NB_EXIT;
	size_t	NB_START;
	size_t	NB_COLLECTIBLES;
}			t_elems;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	**paths;
    
}			t_win;

typedef struct s_vars
{
	t_map	map;
	t_elems	elems;
	t_win	windows;
	size_t	EXIT_FOUND;
	size_t	C_FOUND;
	size_t	WIN;
	t_point	start_p;
}			t_vars;

#endif