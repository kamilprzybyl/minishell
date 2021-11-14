FLAGS = -Wall -Wextra -Werror
LIBFT = Libft/libft.a
NAME = 	minishell
SRC = 	src/main.c \
		src/pipe.c
OBJ = 	$(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	gcc -c $(FLAGS) $^ -o $@

$(NAME): $(LIBFT) $(OBJ)
	gcc ./Libft/libft.a -lreadline $^ -o $@

$(LIBFT):
	make --directory=./Libft

clean:
	rm -fr $(OBJ)

fclean:
	make clean
	rm -fr $(NAME)

re: fclean all