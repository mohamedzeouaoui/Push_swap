NAME := push_swap

SRC := pa_push_a.c rb_rotate_b.c rrb_reve_rotat_b.c \
			rrr_rra_rrb.c sb_swap_b.c pb_push_b.c ra_rotate_a.c \
			rra_reve_rotat_a.c rr_ra_rb.c sa_swap_a.c ss_sa_sb.c

CFILES := ${addprefix instructions/, ${SRC}} push_swap.c function_utils.c ft_atoi_push.c 

OBJS := ${CFILES:.c=.o}

LIB := libft/libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf


all: ${NAME}

${NAME}: ${OBJS} ${LIB}
	${CC} ${OBJS} ${LIB} -o ${NAME}

${LIB}:
	@${MAKE} -C libft/ re --quiet

clean:
	${RM} ${OBJS}
	@make -C libft/ clean --quiet

fclean: clean
	${RM} ${NAME} ${LIB}

re: fclean all

.PHONY: all bonus clean fclean re
