/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/05/18 10:24:41 by ijaber            #+#    #+#             */
/*   Updated: 2024/05/18 10:24:41 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define OPEN_MAX FOPEN_MAX

typedef enum e_line_status
{
	INVALID_LINE,
	VALID_LINE
} t_line_status;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300000
# endif

size_t	ft_strlen(const char *str);
size_t	index_of(const char *str, const char c);
char	*ft_strncpy(char *dest, char *src, size_t size);
char	*strnjoin(char *s1, const char *s2, const size_t n);
void	ft_bzero(void *ptr, size_t size);

char	*get_next_line(int fd);

#endif