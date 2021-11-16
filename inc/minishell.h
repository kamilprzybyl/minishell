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
	char	**envp;
	char	**argv;
	int		argc;
	char	**args;
	int		n;
	int		outfile;
	int		infile;
	int		here_doc;
	char	**env;
}				t_data;

void	pipex(t_data *data);
int		set_env(t_data *data, char **envp);

int		exec_builtin(t_data *data, char **tokens);
int		exec_bin(t_data *data, char **tokens);

int		cd(t_data *data, char **tokens);
int		pwd(t_data *data, char **tokens);
void	echo(t_data *data, char **tokens);
int		export(t_data *data, char **tokens);
int		unset(t_data *data, char **tokens);
void	env(t_data *data, char **tokens);
void	exit(t_data *data, char **tokens);

#endif