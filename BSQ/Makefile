SRCS	= algo.c main.c mapdata.c mapmemory.c \
	readline.c readmap.c str.c solver.c

OBJS	= ${SRCS:.c=.o}

NAME	= bsq

CFLAGS	= -Wall -Werror -Wextra

CC		= gcc
RM		= rm -f

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

${OBJS}: mapdata.h

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}


re: fclean all

.PHONY: all clean fclean re