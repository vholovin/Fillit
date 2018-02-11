/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_xy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:49:16 by vholovin          #+#    #+#             */
/*   Updated: 2017/02/03 15:35:45 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	**ft_tmp(int **tmp, int i, int x, int y)
{
	tmp[1][i] = x;
	tmp[0][i] = y - y / 4 * 4;
	return (tmp);
}

static int	**ft_tmp_end(int **tmp, int i)
{
	tmp[0][i] = -1;
	tmp[1][i] = -1;
	return (tmp);
}

int			**ft_default_xy(char **mass, size_t n)
{
	int	**tmp;
	int	x;
	int	y;
	int	i;

	tmp = (int**)malloc(sizeof(int*) * (2));
	tmp[0] = (int*)malloc(sizeof(int) * (n * 4 + 1));
	tmp[1] = (int*)malloc(sizeof(int) * (n * 4 + 1));
	y = 0;
	i = 0;
	while (mass[y])
	{
		x = 0;
		while (mass[y][x])
		{
			if (mass[y][x] == '#')
				tmp = ft_tmp(tmp, i++, x, y);
			x++;
		}
		y++;
	}
	tmp = ft_tmp_end(tmp, i);
	return (tmp);
}
