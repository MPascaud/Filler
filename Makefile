# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 16:02:42 by mpascaud          #+#    #+#              #
#    Updated: 2018/04/04 15:42:05 by mpascaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler.a

TAGS = -Wall -Werror -Wextra

SRC = mpascaud.filler.c ft_strstr.c get_next_line.c ft_strcpy.c ft_strnew.c \
	  ft_strncat.c ft_strlen.c ft_possible.c ft_board.c ft_piece.c \
	  ft_war.c ft_shapiece.c ft_putchar.c ft_putnbr.c \
	  ft_test.c ft_hot.c ft_heatmap_01p2.c ft_heatmap_00p2.c auxi.c ft_possible_heat.c \
	  ft_heatmap_00p2_auxis.c ft_heatmap.c ft_distance.c ft_heatmap2.c \
	  ft_heatmap_01p2_auxis.c ft_2ndchance.c ft_possible_heat_midground.c \
	  ft_heatmap_auxis.c ft_2ndchance2.c



BIN = $(SRC:.c=.o)


all : $(NAME)

$(NAME) :
	gcc $(TAGS) -c $(SRC)
	ar rc $(NAME) $(BIN)
	ranlib $(NAME)
	gcc -o mpascaud.filler mpascaud.filler.c filler.a

clean:
	rm -fR $(BIN)

fclean: clean
	rm -fR $(NAME)
	rm -rf mpascaud.filler

re: fclean all










