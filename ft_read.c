/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:37:29 by vholovin          #+#    #+#             */
/*   Updated: 2017/02/03 15:40:05 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_error(int i)
{
	if (i == -1)
		write(1, "open() failed\n", 14);
	else if (i == 0)
		write(1, "too much arguments\n", 19);
	else if (i == 1)
		write(1, "close() failed\n", 15);
	exit(0);
}

char			*ft_read(char *file)
{
	int		fd;
	int		i;
	char	c;
	char	buf[BUF_SIZE + 1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(-1);
	i = 0;
	while (read(fd, &c, 1))
	{
		buf[i] = c;
		if (i > BUF_SIZE)
			ft_error(0);
		i++;
	}
	buf[i] = '\0';
	if (close(fd) == -1)
		ft_error(1);
	return (ft_strndup(buf, ft_strlen(buf)));
}
