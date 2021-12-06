FLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
NAME =  minishell
SRC =   src/main.c \
		src/set_env.c \
		src/signals/signals.c \
		src/signals/signals_here_doc.c \
		src/handle_input/handle_input.c \
		src/handle_input/here_doc.c \
		src/handle_input/create_file.c \
		src/handle_input/handle_cmd.c \
		src/builtins/ft_cd.c \
		src/builtins/ft_echo.c \
		src/builtins/ft_env.c \
		src/builtins/ft_exit.c \
		src/builtins/ft_export.c \
		src/builtins/ft_pwd.c \
		src/builtins/ft_unset.c \
		src/exec/exec_builtin.c \
		src/exec/exec_bin.c \
		src/redirections/redirections.c \
		src/parsing/readline.c \
		src/utils/ft_getenv.c \
		src/utils/free_arr.c \
		src/utils/is_number.c \
		src/utils/replace_env.c \
		src/parsing/argv.c \
		src/parsing/helper.c \
		src/parsing/quotes.c \
		src/parsing/quotes1.c \
		src/parsing/redirections.c

OBJ =   $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc -I/Users/$(USER)/.brew/opt/readline/include -c $(FLAGS) $^ -o $@
$(NAME): $(LIBFT) $(OBJ)
	@gcc ./libft/libft.a -lreadline -L/Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include $^ -o $@
	@echo "\033[32m$(NAME) built!\033[0m"
$(LIBFT):
	@make --directory=./libft
clean:
	@rm -fr $(OBJ)
	@make clean -C libft
fclean: clean
	@rm -fr $(NAME)
	@make fclean -C libft
re: fclean all