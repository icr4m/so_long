/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:10:38 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/12 16:51:52 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(int keysym, t_vars *vars)
{
	if (keysym == 65307)
	{
		mlx_destroy_window(vars->windows.mlx_ptr, vars->windows.win_ptr);
		mlx_destroy_display(vars->windows.win_ptr);
		free(vars->windows.mlx_ptr);
		exit(0);
		return (0);
	}
	printf("%d\n", keysym);
	return (1);
}

void	new_window(t_vars *vars)
{
	void	*img;
	int		height;
	int		widht;

	height = 100;
	widht = 100;
	vars->windows.mlx_ptr = mlx_init();
	vars->windows.win_ptr = mlx_new_window(vars->windows.mlx_ptr, 1080, 720,
			"test");
	img = mlx_xpm_file_to_image(vars->windows.mlx_ptr, "assets/aaa.xpm",
			&height, &widht);
	if (img == NULL)
	{
		error_map("flop xpm");
		return ;
	}
	mlx_put_image_to_window(vars->windows.mlx_ptr, vars->windows.win_ptr, img,
		400, 400);
	mlx_hook(vars->windows.win_ptr, KeyPress, KeyPressMask, &on_destroy, &vars);
	mlx_loop(vars->windows.mlx_ptr);
}
