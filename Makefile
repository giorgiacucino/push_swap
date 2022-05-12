NAME = push_swap

SRC = push_swap.c \
	ft_split.c \
	ft_atoi.c \
	ft_putnbr_fd.c \
	moves.c \
	moves2.c

OBJ = $(SRC:.c=.o)

RM = rm -f

HDRS = push_swap.h

%.o: %.c
	gcc -Wall -Wextra -Werror -I ${HDRS} -c $< -o $@

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)
	${RM} $(OBJ)

all: $(NAME)

clean:
	${RM} $(OBJ)

fclean: clean
	${RM} $(NAME) ${OBJ}

re: $(NAME)

.PHONY: all clean fclean re