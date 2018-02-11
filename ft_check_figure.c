/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_figure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:27:19 by vholovin          #+#    #+#             */
/*   Updated: 2017/01/30 16:37:16 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*search(int i, int j, char *s)
{
	if (s[i + 1] == '#' && ((i + 1 >= j * 21) && (i + 1 < (j + 1) * 21)))
	{
		s[i + 1] = '!';
		s = search(i + 1, j, s);
	}
	if (s[i - 1] == '#' && ((i - 1 >= j * 21) && (i - 1 < (j + 1) * 21)))
	{
		s[i - 1] = '!';
		s = search(i - 1, j, s);
	}
	if (s[i + 5] == '#' && ((i + 5 >= j * 21) && (i + 5 < (j + 1) * 21)))
	{
		s[i + 5] = '!';
		s = search(i + 5, j, s);
	}
	if (s[i] == '#' && ((i >= j * 21) && (i < (j + 1) * 21)))
		s[i] = '!';
	return (s);
}

static int		ft_count_figure(int i, char *s)
{
	int res;

	res = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '!')
			res++;
		i++;
	}
	return (res);
}

void			ft_check_figure(int n, char *s)
{
	int	i;
	int	j;

	j = 0;
	while (j < n)
	{
		i = 0 + j * 21;
		while (s[i] && s[i] != '#')
			i++;
		s[i] = '!';
		s = search(i, j, s);
		if (ft_count_figure(i, s) != 4)
		{
			write(1, "error\n", 6);
			exit(0);
		}
		j++;
	}
	while (*s)
	{
		if (*s == '!')
			*s = '#';
		s++;
	}
}
