NAME = philosophers
CC = gcc

SRC = ./philo1.c \
	./generating_philos.c

SRCb = 

OBJ = $(SRC:.c=.o)

OBJb = $(SRCb:.c=.o)

LIBFT = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@$(CC) $(OBJ) ./libft/libft.a -o $(NAME)

bonus: $(OBJb)
	@make -C $(LIBFT)
	@$(CC) $(OBJb) ./libft.a -o $(NAME)

%.o: %.c
	@$(CC) -c $^ -o $@ 2> /dev/null

clean:
	@make fclean -C $(LIBFT)
	@rm -rf $(OBJ) $(OBJb)

fclean: clean
	@rm -rf $(NAME)

re: fclean all