FLAGS = -Wall -Wextra -Werror
LIBFT = Libft/libft.a
NAME = 	minishell
SRC = 	src/main.c \
		src/pipe.c \
		src/set_env.c \
		src/builtins/cd.c \
		src/builtins/echo.c \
		src/builtins/env.c \
		src/builtins/exit.c \
		src/builtins/export.c \
		src/builtins/pwd.c \
		src/builtins/unset.c \
		src/exec/exec_cmd.c \
		src/exec/exec_builtins.c \
		src/exec/exec_bin.c \
		src/redirections/handle_infile.c \
		src/redirections/handle_outfile.c \
		src/parsing/parse.c \
		src/pipe/pipe.c
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