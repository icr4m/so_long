/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:38:14 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/10 14:04:49 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_valid(char c)
{
	if (c == 'WALL')
		return (false);
	return (true);
}

void	path_finder(t_point s_pos, t_vars *vars)
{	
	path_finder((t_point){s_pos.co_x+1,s_pos.co_y}, vars);
	path_finder((t_point){s_pos.co_x,s_pos.co_y+1}, vars);
	path_finder((t_point){s_pos.co_x-1,s_pos.co_y}, vars);
	path_finder((t_point){s_pos.co_x,s_pos.co_y-1}, vars);
}
