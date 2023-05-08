# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 15:27:31 by dcologgi          #+#    #+#              #
#    Updated: 2023/05/04 14:02:14 by dcologgi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variabili di compilazione
NAME = lib/libpushswap.a
NAME_BONUS = lib/libchecker.a
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra

# Directories
SOURCES_DIR = src
OBJECTS_DIR = obj
INCLUDES_DIR = includes
LIB_DIR = lib

# Directories bonus
SOURCES_BONUS_DIR = bonus
OBJECTS_BONUS_DIR = obj_bonus

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

# Sources & objects
SOURCES = ${wildcard ${SOURCES_DIR}/*.c}
OBJECTS = ${patsubst ${SOURCES_DIR}/%.c, ${OBJECTS_DIR}/%.o, ${SOURCES}}

# Sources & object bonus
SOURCES_BONUS = ${wildcard ${SOURCES_BONUS_DIR}/*.c}
OBJECTS_BONUS = ${patsubst ${SOURCES_BONUS_DIR}/%.c, ${OBJECTS_BONUS_DIR}/%.o, ${SOURCES_BONUS}}

all : ${OBJECTS_DIR} ${NAME}
	make all -C ft_printf
	${CC} -o push_swap -L./lib/ -lpushswap -lftprintf
	@echo "${GREEN}Program ft_printf compiled!${DEF_COLOR}"

# Crea directory per gli oggetti
${OBJECTS_DIR} :
	mkdir -p ${OBJECTS_DIR}

# Regola per la library
${NAME} : ${OBJECTS}
	@if [ ! -d ${LIB_DIR} ]; then mkdir -p ${LIB_DIR}; fi
	ar rcs ${NAME} ${OBJECTS}
	@echo "${GREEN}Program push_swap compiled!${DEF_COLOR}"

# Compilazione oggetti
${OBJECTS_DIR}/%.o: ${SOURCES_DIR}/%.c
	${CC} -c -o $@ $< ${CFLAGS} -I${INCLUDES_DIR}
	@echo "${YELLOW}Compiling: $< ${DEF_COLOR}"

clean :
	${RM} ${OBJECTS_DIR}
	${RM} ${OBJECTS_BONUS_DIR}
	@echo "${WHITE}Object files cleaned!${DEF_COLOR}"

fclean :
	make fclean -C ft_printf
	make fclean -C bonus
	${RM} ${NAME} push_swap
	${RM} ${NAME_BONUS} checker
	@if [ -d ${OBJECTS_DIR} ]; then ${RM} ${OBJECTS_DIR}; fi
	@if [ -d ${OBJECTS_BONUS_DIR} ]; then ${RM} ${OBJECTS_BONUS_DIR}; fi
	@echo "${CYAN}Executable files cleaned!${DEF_COLOR}"

re : clean
	@if [ -d ${OBJECTS_DIR} ]; then ${RM} ${OBJECTS_DIR}; fi
	mkdir -p ${OBJECTS_DIR}
	@if [ -d ${OBJECTS_BONUS_DIR} ]; then ${RM} ${OBJECTS_BONUS_DIR}; fi
	mkdir -p ${OBJECTS_BONUS_DIR}
	${MAKE} all
	@echo "${BLUE}Cleaned and rebuilt everything for push_swap!${DEF_COLOR}"

# Regola bonus
bonus : ${OBJECTS_BONUS_DIR} ${NAME_BONUS}
	make all -C ft_printf
	${CC} -o checker -L./lib/ -lchecker -lftprintf
	@echo "${GREEN}Program bonus compiled!${DEF_COLOR}"

# Directory bonus
${OBJECTS_BONUS_DIR} :
	mkdir -p ${OBJECTS_BONUS_DIR}

# Library bonus
${NAME_BONUS} : ${OBJECTS_BONUS}
	@if [ ! -d ${LIB_DIR} ]; then mkdir -p ${LIB_DIR}; fi
	ar rcs ${NAME_BONUS} ${OBJECTS_BONUS}
	@echo "${GREEN}Program checker compiled!${DEF_COLOR}"

# Compilazione bonus
${OBJECTS_BONUS_DIR}/%.o: ${SOURCES_BONUS_DIR}/%.c
	${CC} -c -o $@ $< ${CFLAGS} -I${INCLUDES_DIR}
	@echo "${YELLOW}Compiling: $< ${DEF_COLOR}"
