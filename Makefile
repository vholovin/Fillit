# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vholovin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/29 16:04:52 by vholovin          #+#    #+#              #
#    Updated: 2017/02/03 16:32:26 by vholovin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEAD = fillit.h

HEAD_GCH = $(HEAD:.h=.h.gch)

FLAGS = -Wall -Wextra -Werror

SRC = ft_main.c			\
	ft_read.c			\
	ft_strlen.c			\
	ft_strnew.c			\
	ft_strncpy.c		\
	ft_strndup.c		\
	ft_strsplit.c		\
	ft_number_block.c	\
	ft_check_figure.c	\
	ft_default_xy.c		\
	ft_memalloc.c		\
	ft_memset.c			\
	ft_empty.c			\
	ft_update_xy.c		\
	ft_result.c			\
	ft_putendl.c		\
	ft_putstr.c			\
	ft_putchar.c		\
	ft_putchar_fd.c		\

SRO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRO)
		@gcc -c $(FLAGS) $(SRC) $(HEAD)
		@gcc -o $(NAME) $(SRO)


clean:
		@rm -f $(SRO) $(HEAD_GCH)

fclean:
		@make clean
		@rm -f $(NAME)

re:
		@make fclean
		@make all
