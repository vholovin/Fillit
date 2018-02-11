/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 15:55:47 by vholovin          #+#    #+#             */
/*   Updated: 2017/02/03 16:32:13 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUF_SIZE 1000

void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_read(char *file);
size_t	ft_strlen(const char *s);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strndup(const char *s, size_t n);
char	**ft_strsplit(char const *s, char c);
int		ft_number_block(char *str);
void	ft_check_figure(int n, char *s);
int		**ft_default_xy(char **mass, size_t n);
char	*ft_strnew(size_t size);
char	**ft_empty(char **tab, int max);
int		**ft_update_xy(int **mass, int n, int x, int y);
char	**ft_result(int **mass);

#endif
