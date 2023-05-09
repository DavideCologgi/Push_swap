# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 15:27:31 by dcologgi          #+#    #+#              #
#    Updated: 2023/05/09 11:38:34 by dcologgi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap
NAME_BONUS = checker
PRINTF_PATH = ft_printf/
PRINTF = $(PRINTF_PATH)libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS += --silent
RM = rm -rf

SRCS_DIR = src
SRCS_BONUS_DIR = bonus
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = ${SRCS:.c=.o}

SRCS_BONUS = $(wildcard $(SRCS_BONUS_DIR)/*.c)
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS) $(PRINTF)
	$(CC) $(OBJS) $(PRINTF) -o $(NAME)
	@echo "${GREEN}Program push_swap successfully compiled!${DEF_COLOR}"

$(PRINTF) :
	make -C $(PRINTF_PATH)

all : $(NAME)

bonus : $(OBJS_BONUS) $(PRINTF)
	$(CC) $(OBJS_BONUS) $(PRINTF) -o $(NAME_BONUS)
	@echo "${GREEN}Program checker successfully compiled!${DEF_COLOR}"

clean :
	${RM} ${OBJS}
	${RM} ${OBJS_BONUS}
	make clean -C ${PRINTF_PATH}
	@echo "$(BLUE)Objects cleared!$(DEF_COLOR)"

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f ${PRINTF}
	@echo "$(BLUE)Executable cleared!$(DEF_COLOR)"

re: fclean all

.PHONY:	all clean fclean re
