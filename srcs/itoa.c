/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:19:44 by ijaber            #+#    #+#             */
/*   Updated: 2024/06/24 13:40:55 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static unsigned int	get_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static size_t	nb_len(int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	fill_number(char *src, int nb, unsigned int len)
{
	unsigned int	i;
	unsigned int	n_abs;

	i = 0;
	n_abs = get_abs(nb);
	while (i < len)
	{
		src[len - i - 1] = (n_abs % 10) + '0';
		n_abs /= 10;
		i++;
	}
	src[len] = '\0';
}

char	*ft_itoa(int n)
{
	char	*new;
	int		len;
	bool	is_neg;

	if (n == 0)
		return (ft_strdup("0"));
	is_neg = (n < 0);
	len = nb_len(n);
	new = (char *)malloc((len + is_neg) * sizeof(char) + 1);
	if (!new)
		return (0);
	if (is_neg)
		new[0] = '-';
	fill_number(new + is_neg, n, len);
	return (new);
}
