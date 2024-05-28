/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:31:43 by ijaber            #+#    #+#             */
/*   Updated: 2024/05/28 12:17:47 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win_ptr);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
		return (1);
	}
	else
	{
		on_keypress(keycode, data);
	}
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\n", keysym);
	return (0);
}

int	main(void)
{
	t_data		data;
	win_data	img;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx, 420, 420, "test");
	if (!data.win_ptr)
		return (free(data.mlx), 1);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &close, &data);
	mlx_loop(data.mlx);
}
