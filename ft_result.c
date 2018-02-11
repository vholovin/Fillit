/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:49:16 by vholovin          #+#    #+#             */
/*   Updated: 2017/02/03 16:33:01 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_reset(char **tab, int n, int max)
{
	int		x;
	int		y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tab[y][x] == 'A' + n - 1)
				tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (tab);
}

static char		**ft_saved(char **tab, int **mass, int n)
{
	int		i;

	i = (n - 1) * 4;
	while (i < n * 4)
	{
		tab[mass[0][i]][mass[1][i]] = 'A' + n - 1;
		i++;
	}
	return (tab);
}

static int		ft_check(char **tab, int **mass, int n, int max)
{
	int		x;
	int		y;
	int		i;
	int		k;

	k = 0;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			i = (n - 1) * 4;
			while (i < n * 4)
			{
				if (mass[0][i] == y && mass[1][i] == x && tab[y][x] == '.')
					k++;
				i++;
			}
			x++;
		}
		y++;
	}
	return ((k == 4) ? 1 : 0);
}

static char		**ft_solve(char **tab, int **mass, int n_m, int max)
{
	int		x;
	int		y;
	char	**tmp;

	if (mass[0][(n_m - 1) * 4] < 0 && mass[1][(n_m - 1) * 4] < 0)
		return (tab);
	tmp = NULL;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			mass = ft_update_xy(mass, n_m, x, y);
			if (ft_check(tab, mass, n_m, max))
				tmp = ft_solve(ft_saved(tab, mass, n_m), mass, n_m + 1, max);
			if (tmp)
				return (tmp);
			tab = ft_reset(tab, n_m, max);
			++x;
		}
		++y;
	}
	return (NULL);
}

char			**ft_result(int **mass)
{
	char	**tab;
	int		max;

	max = 2;
	tab = NULL;
	while (!tab)
	{
		tab = ft_empty(tab, max);
		tab = ft_solve(tab, mass, 1, max);
		max++;
	}
	return (tab);
}
