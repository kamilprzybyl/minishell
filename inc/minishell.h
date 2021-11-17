#ifndef MINISHELL_H
# define MINISHELL_H

#include "../Libft/inc/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_builtins
{
	char	*cmd;
	void	(*f)(t_data *data, char **tokens);
}				t_builtins;

typedef struct s_data
{
	char	**args;
	char	**tokens;
	int		outfile;
	int		infile;
	int		here_doc;
	int		redirections;
	int		pipe;
}				t_data;

char	**g_env;

int		set_env(char **envp);

int		parse(t_data *data, char *input);

void	redirect(t_data *data);

void	exec_cmd(t_data *data, char **tokens);
int		exec_builtin(t_data *data, char **tokens);
int		exec_bin(t_data *data, char **tokens);

int		handle_outfile(t_data *data);
int		handle_infile(t_data *data);

int		cd(t_data *data, char **tokens);
int		pwd(t_data *data, char **tokens);
void	echo(t_data *data, char **tokens);
int		export(t_data *data, char **tokens);
int		unset(t_data *data, char **tokens);
void	env(t_data *data, char **tokens);
void	exit(t_data *data, char **tokens);

#endif