.PHONY: all clean fclean re makelib build

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_FILE = ft_printf.c\
		printf_num.c\
		printf_char.c\
		printf_hexa.c

OBJ = ${SRC_FILE:.c=.o}

LIB_NAME = libft.a
LIB_DIR = libft/
LIB = ${LIB_DIR}${LIB_NAME}

INC = -I . -I ${LIB_DIR}

%.o: %.c 
		${CC} ${CFLAGS} ${INC} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ} ft_printf.h
		${MAKE} makelib
		ar -rcs ${NAME} ${OBJ}

makelib:
		${MAKE} -C ${LIB_DIR}
		cp ${LIB} ${NAME}

clean:
		rm -f ${OBJ}

fclean: 
		${MAKE} -C ${LIB_DIR} fclean
		${MAKE} clean
		rm -f ${NAME}

re:
		${MAKE} fclean
		${MAKE} all

build:
		${MAKE}
		${CC} ${CFLAGS} ${INC} main.c ${NAME}
