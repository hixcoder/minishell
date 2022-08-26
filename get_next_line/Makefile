# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 15:50:56 by hboumahd          #+#    #+#              #
#    Updated: 2022/02/15 16:00:38 by hboumahd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c

SRCOBJ = ${SRC:.c=.o}

INCLUDE = get_next_line.h  

CC = cc 

FLAGS = -Wall -Wextra -Werror

%.o : %.c ${INCLUDE}
	${CC} ${FLAGS} -c $< -o $@

$(NAME) : ${SRCOBJ} 
	@ar rcs ${NAME} ${SRCOBJ} 
	@mv ${NAME} ..

all : $(NAME)

clean :
	rm -f ${SRCOBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all
