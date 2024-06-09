/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:48:18 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/09 03:17:47 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(char *str)
{
	ft_printf("Error: ");
	ft_printf("%s \n", str);
	exit(1);
}

bool	strchr(char *line, char c)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line != 'c')
			return (0);
		i++;
	}
}
