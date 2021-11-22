FLAGS = -Wall -Wextra -Werror
LIBFT = Libft/libft.a
NAME = 	minishell
SRC = 	src/main.c \
		src/set_env.c \
		src/handle_input.c \
		src/builtins/ft_cd.c \
		src/builtins/ft_echo.c \
		src/builtins/ft_env.c \
		src/builtins/ft_exit.c \
		src/builtins/ft_export.c \
		src/builtins/ft_pwd.c \
		src/builtins/ft_unset.c \
		src/exec/exec_cmd.c \
		src/exec/exec_builtin.c \
		src/exec/exec_bin.c \
		src/redirections/redirections.c \
		src/redirections/handle_infile.c \
		src/redirections/handle_outfile.c \
		src/parsing/parse.c
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