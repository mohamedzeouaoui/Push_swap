NAME := libftprintf.a
CFILES := ft_printf.c ft_putchar.c ft_putnbr.c ft_putp.c ft_putstr.c ft_putnbr_u.c ft_putnbr_base.c
OBJS := ${CFILES:.c=.o}
CC := cc
CFLAGS := -Wall -Wextra -Werror
AR := ar rcs
RM := rm -f

all: ${NAME}

${NAME}: ${OBJS}

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@
	${AR} ${NAME} $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
