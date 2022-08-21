# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 13:03:02 by hboumahd          #+#    #+#              #
#    Updated: 2022/08/21 12:59:44 by ahammam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# madatory
PARSING_FOLDER = ./parsing/
PARSING_FILES  = parse.c quotes.c ft_split2.c utiles.c expand.c expand_2.c ft_strreplace.c tokenize.c syntax_error.c
SRCS_PARSING = $(addprefix $(PARSING_FOLDER), $(PARSING_FILES))

# execution
EXECUTION_FOLDER = ./builtins/
EXECUTION_FILES  = ft_echo.c ft_cd.c ft_pwd.c ft_export.c utile_export.c export_append.c ../free/split_free.c
SRCS_EXECUTION = $(addprefix $(EXECUTION_FOLDER), $(EXECUTION_FILES))

REDIRECTIONS_FOLDER = ./redirections/
REDIRECTIONS_FILES  = redirections_check.c 
SRCS_REDIRECTIONS = $(addprefix $(REDIRECTIONS_FOLDER), $(REDIRECTIONS_FILES))

SRCS = main.c $(SRCS_PARSING) $(SRCS_REDIRECTIONS) ${SRCS_EXECUTION}


LIBFT_FOLDER = ./libft/
LIBFT_FILES =	ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c\
				ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_itoa.c ft_atoi.c ft_putendl_fd.c\
				ft_strlcpy.c ft_tolower.c ft_bzero.c  ft_putnbr_fd.c ft_strlen.c\
				ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c\
				ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
				ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_striteri.c \
				ft_lstnew.c ft_lstlast.c ft_lstadd_back.c ft_lstadd_front.c ft_lstsize.c ft_strcat.c 
				
SRCS_LIBFT = $(addprefix $(LIBFT_FOLDER), $(LIBFT_FILES))

ALL_SRCS = $(SRCS) $(SRCS_LIBFT)
ALL_OBJ = ${ALL_SRCS:.c=.o}

INCLUDES = minishell.h ./libft/libft.h
LIBS = libft.a

# -g for the debugger
FLAGS = -Wall -Wextra -Werror -g 
CC = gcc 

%.o : %.c ${INCLUDES}
	$(CC) ${FLAGS} -c $< -o $@
	
$(NAME) : ${ALL_OBJ}
	@echo "|+| make the libft.a library   ==> ${GREEN}DONE${RESET}"	
	@$(MAKE) -C $(LIBFT_FOLDER)
	@echo "|+| make the minishell program ==> ${GREEN}DONE${RESET}"
	@$(CC) ${FLAGS} $(ALL_OBJ) $(LIBS) -lreadline -o $(NAME)
	make clean
	clear

all : $(NAME) 

clean :
	@rm -f $(ALL_OBJ) $(LIBS)
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