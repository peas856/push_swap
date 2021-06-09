NAME = push_swap

FLAGS = -Wall -Wextra -Werror

INC	= -I include -I libft

LFT	= libft/libft.a

SRCS = check_arg.c command.c quick.c stack.c main.c quick_sub.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(LFT) $(OBJ)
	gcc $(FLAGS) -o $@ $^

%.o : %.c
	gcc $(FLAGS) $(INC) -c -o $@ $<

$(LFT):
	make -C libft all

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all