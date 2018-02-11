/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:58:36 by vholovin          #+#    #+#             */
/*   Updated: 2017/01/30 16:49:05 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		check_format(char *str)
{
	int i;
	int row;

	row = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i - 1] == '.' || str[i - 1] == '#'))
			row++;
		if (row > 4)
		{
			write(1, "error\n", 6);
			exit(0);
		}
		if (str[i] == '\n' && str[i - 1] == '\n')
			row = 0;
		if (str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] == '\n')
		{
			write(1, "error\n", 6);
			exit(0);
		}
		i++;
	}
}

static void		error(int tochka, int figure, int endl)
{
	if (figure < 4 || !tochka)
	{
		write(1, "error\n", 6);
		exit(0);
	}
	if (tochka % 4 || figure % 4 || (endl + 1) % 5)
	{
		write(1, "error\n", 6);
		exit(0);
	}
}

static void		pr_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

int				ft_number_block(char *str)
{
	int tochka;
	int figure;
	int endl;
	int i;

	check_format(str);
	i = 0;
	tochka = 0;
	figure = 0;
	endl = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			tochka++;
		else if (str[i] == '#')
			figure++;
		else if (str[i] == '\n')
			endl++;
		else if (str[i] != '.' || str[i] != '#' || str[i] != '\n')
			pr_error();
		i++;
	}
	error(tochka, figure, endl);
	return (figure / 4);
}
