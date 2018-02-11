/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_xy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 15:55:47 by vholovin          #+#    #+#             */
/*   Updated: 2017/01/30 16:21:07 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_update_xy(int **mass, int n, int x, int y)
{
	int	xmin;
	int	ymin;
	int	i;

	ymin = mass[0][(n - 1) * 4];
	xmin = mass[1][(n - 1) * 4];
	i = (n - 1) * 4;
	while (i < n * 4)
	{
		if (mass[0][i] < ymin)
			ymin = mass[0][i];
		if (mass[1][i] < xmin)
			xmin = mass[1][i];
		i++;
	}
	i = (n - 1) * 4;
	while (i < n * 4)
	{
		mass[0][i] = mass[0][i] - ymin + y;
		mass[1][i] = mass[1][i] - xmin + x;
		i++;
	}
	return (mass);
}
