NAME = push_swap
BNAME = checker

SRC = push_swap.c \
	init_stacks.c \
	order.c \
	ft_split.c \
	ft_atoi.c \
	ft_putnbr_fd.c \
	moves.c \
	moves2.c \
	moves3.c \
	moves4.c \
	moves_utils.c \
	lis.c \
	lis2.c \
	debug_print.c \
	utils.c \
	utils_sort.c

BSRC =	get_next_line.c \
	get_next_line_utils.c \
	init_stacks.c \
	order.c \
	checker.c \
	ft_split.c \
	ft_atoi.c \
	ft_putnbr_fd.c \
	moves.c \
	moves2.c \
	moves3.c \
	moves4.c \
	moves_utils.c \
	lis.c \
	lis2.c \
	debug_print.c \
	utils.c \
	utils_sort.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

RM = rm -f

HDRS = push_swap.h

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)
	${RM} $(OBJ)

bonus: $(BOBJ)
	gcc $(BOBJ) -o $(BNAME)

all: $(NAME)

clean:
	${RM} $(OBJ) $(BOBJ)

fclean: clean
	${RM} $(NAME) $(BNAME) ${OBJ} ${BOBJ}

re: $(NAME)

.PHONY: all clean fclean re