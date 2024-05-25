/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:31:43 by ijaber            #+#    #+#             */
/*   Updated: 2024/05/25 17:42:59 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	void	*mlx;
	void	*win_ptr;
}			t_data;

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win_ptr);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	static size_t	count;

	(void)data;
	count = 0;
	printf("Pressed key: %d\\n", keysym)
		count++;
	return (count);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx, 420, 420, "test");
	if (!data.win_ptr)
		return (free(data.mlx), 1);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		&data);
	mlx_loop(data.mlx);
	mlx_loop(data.mlx);
}
