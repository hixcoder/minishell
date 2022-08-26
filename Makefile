# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 13:03:02 by hboumahd          #+#    #+#              #
#    Updated: 2022/08/26 10:21:23 by hboumahd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

#parsing
PARSING_FOLDER = ./parsing/
PARSING_FILES  =	parse.c quotes.c ft_split2.c utiles.c expander.c expand_2.c ft_strreplace.c \
					tokenizer.c syntax_error.c spliter.c ft_split4.c herdoc.c   
SRCS_PARSING = $(addprefix $(PARSING_FOLDER), $(PARSING_FILES))

# execution
EXECUTION_FOLDER = ./execution/
EXECUTION_FILES  = ./builtins/ft_echo.c ./builtins/ft_pwd.c ./builtins/ft_cd.c ./builtins/ft_env.c \
					./builtins/ft_export.c ./builtins/utile_export.c ./builtins/export_append.c \
					./builtins/ft_unset.c
SRCS_EXECUTION = $(addprefix $(EXECUTION_FOLDER), $(EXECUTION_FILES))

# redirection
REDIRECTIONS_FOLDER = ./redirections/
REDIRECTIONS_FILES  = redirections_check.c redirector.c
SRCS_REDIRECTIONS = $(addprefix $(REDIRECTIONS_FOLDER), $(REDIRECTIONS_FILES))

# all sources
SRCS = main.c $(SRCS_PARSING) $(SRCS_REDIRECTIONS) $(SRCS_EXECUTION)
ALL_OBJ = ${SRCS:.c=.o}

# external libs
LIBFT_FOLDER = ./libft/
GET_NEXT_LINE_FOLDER = ./get_next_line/

INCLUDES = minishell.h ./libft/libft.h
LIBS = libft.a get_next_line.a

# -g for the debugger
FLAGS = -Wall -Wextra -Werror -g 
CC = gcc 

%.o : %.c ${INCLUDES}
	$(CC) ${FLAGS} -c $< -o $@
	
$(NAME) : ${ALL_OBJ}
	@echo "|+| make the libft.a library   ==> ${GREEN}DONE${RESET}"	
	@$(MAKE) -C  $(LIBFT_FOLDER)
	@$(MAKE) -C  $(GET_NEXT_LINE_FOLDER)
	@echo "|+| make the minishell program ==> ${GREEN}DONE${RESET}"
	@$(CC) ${FLAGS} $(ALL_OBJ) $(LIBS) -lreadline -o $(NAME)
	clear

all : $(NAME) 

clean :
	@rm -f $(ALL_OBJ) $(LIBS)
	@rm -f $(ALL_OBJ) $(LIBS)
	@$(MAKE) -C $(LIBFT_FOLDER) clean
	@$(MAKE) -C  $(GET_NEXT_LINE_FOLDER) clean
	@echo "|-| remove object files ==> ${RED}DONE${RESET}"

fclean : clean
	@rm -f ${NAME}
	@echo "|-| remove the program  ==> ${RED}DONE${RESET}"

re : fclean all


# colors used
GREEN = \033[0;92m
RED = \033[0;91m
RESET = \033[0m

#command for see all colors that you can use
# ===>   bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'  <===