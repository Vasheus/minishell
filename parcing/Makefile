# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 11:46:55 by yosabir           #+#    #+#              #
#    Updated: 2024/10/02 13:54:13 by yosabir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRCS = $(wildcard *.c)
OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra -fsanitize=address
CC = cc

all: $(NAME)

$(NAME):  $(OBJECTS)
	$(CC) $(FLAGS) -o $@ $(OBJECTS) -lreadline

%.o: %.c minishell.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
	