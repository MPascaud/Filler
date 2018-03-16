# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 16:02:42 by mpascaud          #+#    #+#              #
#    Updated: 2018/03/16 17:29:48 by mpascaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler.a

TAGS =

SRC = mpascaud.filler.c ft_strstr.c get_next_line.c ft_strcpy.c ft_strnew.c \
	  ft_strncat.c ft_strlen.c ft_possible.c ft_heatmap.c ft_board.c ft_piece.c \
	  ft_war.c ft_shapiece.c afficher_variables.c ft_putchar.c ft_putnbr.c \



BIN = $(SRC:.c=.o)


all : $(NAME)

$(NAME) :
	gcc $(TAGS) -c $(SRC)
	ar rc $(NAME) $(BIN)
	ranlib $(NAME)

clean:
	rm -fR $(BIN)

fclean: clean
	rm -fR $(NAME)

re: fclean all










