/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:48:18 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/21 02:04:46 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(char *str)
{
	ft_printf(Red "Error: " White);
	ft_printf("%s \n", str);
	exit(1);
}

int	input_manager(int keynb, t_vars *vars)
{
	if (keynb == ECHAP)
	{
		free_final(vars);
		return (0);
	}
	if (keynb == UP || keynb == UP2)
		
	if (keynb == RIGHT || keynb == RIGHT2)
		if (keynb == LEFT || keynb == LEFT2)
			if (keynb == DOWN || keynb == DOWN2)
				return (0);
}
