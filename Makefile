# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 12:11:11 by jamerlin          #+#    #+#              #
#    Updated: 2017/10/13 12:01:50 by jamerlin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = srcs/ft_tools.c \
	srcs/ls.c \
	srcs/print.c \
	srcs/ft_do_ls.c \
	srcs/ft_putchar.c \
	srcs/ft_putstr.c \
	srcs/ft_putnbr.c \
	srcs/ft_strcmp.c \
	srcs/ft_strdup.c \
	srcs/ft_strjoin.c \
	srcs/ft_strcat.c \
	srcs/ft_strcpy.c \
	srcs/ft_strlen.c \
	srcs/ft_strnew.c \
	srcs/ft_memset.c \
	srcs/ft_recurs.c \
	srcs/ft_strsub.c \
	srcs/ft_putstr_fd.c \
	srcs/ft_bzero.c \
	srcs/checking.c \
	srcs/complete_chain_link.c \
	srcs/count_len.c \
	srcs/error.c \
	srcs/free.c \
	srcs/ft_itoa.c \
	srcs/ft_put_unsigned_int.c \
	srcs/get_date.c \
	srcs/init_stats.c \
	srcs/print_space.c \
	srcs/sort_tab.c \
	srcs/sort.c \
	srcs/stock_args.c \
	srcs/law.c \

CC = gcc 

CFLAGS = -c -Wall -Wextra -Werror -I ./includes 

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all : $(NAME)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
