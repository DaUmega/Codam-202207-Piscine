SRCS	= assign_values.c dict_memory.c dict_read.c \
	inputexplosion.c main.c parse_key_value.c readline.c str.c writer.c

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

CFLAGS	= -Wall -Werror -Wextra 

CC		= gcc
RM		= rm -f

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}


re: fclean all

.PHONY: all clean fclean re
