NAME = push_swap
BONUS = checker

SRC = pa_push_a.c rb_rotate_b.c rrb_reve_rotat_b.c \
			rrr_rra_rrb.c sb_swap_b.c pb_push_b.c ra_rotate_a.c \
			rra_reve_rotat_a.c rr_ra_rb.c sa_swap_a.c ss_sa_sb.c

CFILES = ${addprefix instructions/, ${SRC}} push_swap.c function_utils.c \
			ft_atoi_push.c ft_lstadd_back.c ft_lstlast.c ft_lstnew.c \
			algo.c ft_lstsize.c garbage_collector.c algo_utils.c algo_three.c\
			function_utils_1.c function_utils_2.c\

CFILESB = ${addprefix instructions/, ${SRC}} checker.c get_next_line.c function_utils_bonus.c \
			ft_atoi_push.c ft_lstadd_back.c ft_lstlast.c ft_lstnew.c algo_utils.c \
			algo.c ft_lstsize.c garbage_collector.c get_next_line_utils.c algo_three.c\
			function_utils_1.c function_utils_2.c function_main_bonus.c \

OBJS = ${CFILES:.c=.o}
OBJSB = ${CFILESB: .c=.o}

LIB = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf


all: ${NAME}
bonus: ${BONUS}

${NAME}: ${OBJS} ${LIB}
	${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}

${BONUS}: ${OBJSB} ${LIB}
	${CC} ${CFLAGS} ${OBJSB} ${LIB} -o ${BONUS}

${LIB}:
	@${MAKE} -C libft/ bonus --quiet

clean:
	${RM} ${OBJS}
	@make -C libft/ clean --quiet

fclean: clean
	${RM} ${NAME} ${LIB}

re: fclean all

.PHONY: all bonus clean fclean re
.SECONDARY: ${OBJS} ${OBJSB}
