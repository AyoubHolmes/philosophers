NAME = philosophers
CC = gcc

SRC = ./main.c \
	./generating_philos.c \
	./utils/ft_atoi.c \
	./utils/ft_isdigit.c \

SRCb = 

OBJ = $(SRC:.c=.o)

OBJb = $(SRCb:.c=.o)

LIBFT = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

bonus: $(OBJb)
	@$(CC) $(OBJb) -o $(NAME)

%.o: %.c
	@$(CC) -c $^ -o $@ 2> /dev/null

clean:
	@rm -rf $(OBJ) $(OBJb)
	@rm -rf debug*

fclean: clean
	@rm -rf $(NAME)

re: fclean all