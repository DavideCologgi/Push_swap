# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 11:45:24 by dcologgi          #+#    #+#              #
#    Updated: 2023/05/04 11:57:51 by dcologgi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../lib/libbonus.a

SOURCES = checker.c checker_utils.c get_next_line.c get_next_line_utils.c

OBJECTS = ${SOURCES:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

.o.c:
	${CC} ${CFLAGS} ${OBJECTS} $< -o ${<:.c=.o}

${NAME}: ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}

all: ${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all
