/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:31:43 by ijaber            #+#    #+#             */
/*   Updated: 2024/05/28 13:38:34 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx, 420, 420, "test");
	if (!data.win_ptr)
		return (free(data.mlx), 1);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &close, &data);
	mlx_loop(data.mlx);
}
