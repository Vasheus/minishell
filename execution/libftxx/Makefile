 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 19:39:27 by ael-garr          #+#    #+#              #
#    Updated: 2023/12/02 17:20:44 by ael-garr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BASIC_SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_strncmp.c \
            ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_calloc.c \
			ft_strdup.c ft_substr.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
			ft_substr.c 
#ft_strjoin.c
 
BASIC_BNS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c


OBJ_SRC = $(BASIC_SRC:.c=.o) 
OBJ_BNS = $(BASIC_BNS:.c=.o)
HEADER = libft.h
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJ_SRC)
	ar rcs $(NAME) $(OBJ_SRC)

bonus: $(OBJ_BNS)
	ar rcs $(NAME) $(OBJ_BNS)

clean:
	rm -f $(OBJ_SRC) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY : clean fclean re
