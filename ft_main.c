/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 15:54:18 by vholovin          #+#    #+#             */
/*   Updated: 2017/02/03 15:38:35 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	**result;
	int		**mass;
	char	*str;
	int		n;

	if (argc != 2)
		write(1, "Use fillit input file\n", 22);
	else
	{
		str = ft_read(argv[1]);
		n = ft_number_block(str);
		ft_check_figure(n, str);
		mass = ft_default_xy(ft_strsplit(str, '\n'), n);
		result = ft_result(mass);
		while (*result)
			ft_putendl(*result++);
		free(mass);
	}
	return (0);
}
