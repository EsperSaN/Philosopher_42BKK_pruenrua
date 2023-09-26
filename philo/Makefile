NAME = philo

CC = cc

FLAGS = -Wall -Werror -Wextra

THREAD_F = -lpthread

SRC = util.c monitor.c routine.c init_n_checker.c free.c main.c

OBJ = ${SRC:.c=.o}
all = ${NAME}

${NAME} : ${OBJ}
	${CC} ${FLAGS} ${THREAD_F} ${OBJ} -o ${NAME}

clean :
	rm -rf ${OBJ}

fclean : clean 
	rm -rf ${NAME}

re : fclean ${NAME}

.PHONY : all clean fclean