# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-garr <ael-garr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 03:45:54 by ael-garr          #+#    #+#              #
#    Updated: 2024/10/21 11:25:12 by ael-garr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BASIC_SRC = main.c libft/ft_sort_params.c libft/ft_strjoin.c libft/ft_strncmp.c libft/ft_isdigit.c libft/ft_split.c libft/ft_putstr_fd.c libft/ft_isalpha.c libft/ft_strlen.c libft/ft_strdup.c libft/ft_strchr.c libft/ft_lstsize_bonus.c libft/ft_lstadd_back_bonus.c libft/ft_strlcpy.c libft/ft_lstnew_bonus.c libft/%%%%%%to_linked_list.c\
			BUILT_INS/ft_pwd.c BUILT_INS/cd.c BUILT_INS/ft_export.c BUILT_INS/echo.c BUILT_INS/ft_exit.c BUILT_INS/env.c BUILT_INS/ft_export_utils.c BUILT_INS/ft_unset.c\
			errors/error_export.c errors/error_export_2_args.c\
			init_signals.c\
			exe/exec_simple_command.c\
			utils/ft_find_node.c utils/ft_free_table.c utils/joinning_and_free.c utils/small_parse.c\
			exe_commands/exec_commands.c exe_commands/multi_commands.c\
			../parcing/classing.c ../parcing/expand.c ../parcing/helper2.c ../parcing/herdeocfile.c ../parcing/helper.c ../parcing/lst.c  ../parcing/ofred.c ../parcing/parsing.c ../parcing/parsing_word_space.c ../parcing/settinglist.c ../parcing/syntax1.c ../parcing/syntax2.c\
			utils/for_merging.c\
			signals/init_signals.c\
			test_node_content.c\
			garbage_collector/g_collector.c



OBJ = ${BASIC_SRC:.c=.o}
CFLAG = -Wall -Wextra -Werror -g  #-fsanitize=address
NAME = minishell
READLINE_L = $(shell brew --prefix readline)/lib
READLINE_I = $(shell brew --prefix readline)/include
CC = cc

all : ${NAME}

%.o: %.c includes/minishell.h
		@${CC} ${CFLAG} -I ${READLINE_I} -c $< -o $@
		
$(NAME): $(OBJ) 
		${CC} ${CFLAG} ${OBJ} -L ${READLINE_L} -o ${NAME} -lreadline

norm :
	@norminette

clean :
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : clean norm
