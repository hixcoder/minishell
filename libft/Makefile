# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 13:41:31 by hboumahd          #+#    #+#              #
#    Updated: 2022/08/25 22:45:13 by hboumahd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c\
		ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_itoa.c ft_atoi.c ft_putendl_fd.c\
		ft_strlcpy.c ft_tolower.c ft_bzero.c  ft_putnbr_fd.c ft_strlen.c\
		ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c\
		ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
		ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_striteri.c\
		ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c\
		ft_lstnew.c ft_lstsize.c ft_lstclear.c ft_lstiter.c ft_add_string.c ft_strcat.c\
		ft_strcmp.c 

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c\
		ft_lstnew.c ft_lstsize.c ft_lstclear.c ft_lstiter.c

OBJSRC = ${SRCS:.c=.o}

OBJBONUS = ${BONUS:.c=.o}

CC = cc

Include = libft.h

%.o:%.c ${Include}
		${CC} ${CFLAGS} -g -c $< -o $@

$(NAME): ${OBJSRC} 
	@ar rcs ${NAME} ${OBJSRC}
	@mv ${NAME} ..

bonus : ${OBJBONUS} ${OBJSRC} ${Include}
	ar rcs ${NAME} ${OBJSRC} ${OBJBONUS}

all: ${NAME}

clean:
	rm -f ${OBJSRC} ${OBJBONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all

rm:
	@rm -f *.o
