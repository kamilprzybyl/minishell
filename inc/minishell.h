#ifndef MINISHELL_H
# define MINISHELL_H

#include "../Libft/inc/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_data
{
	char	**args;
	// char	**tokens;
	char	***cmnds;
	int		n;
	int		outfile;
	int		infile;
	int		here_doc;
	int		redirections;
	int		pipe;
}				t_data;

typedef struct s_builtins
{
	char	*cmd;
	void	(*f)(t_data *data, char **tokens);
}				t_builtins;

char	**g_env;

int		set_env(char **envp);

void	handle_input(t_data *data, char *input);
int		parse(t_data *data, char *input);

void	redirect(t_data *data, char **tokens, int i);

void	exec_cmd(t_data *data, char **tokens);
int		exec_builtin(t_data *data, char **tokens);
int		exec_bin(char **tokens);

int		handle_outfile(t_data *data, char *file);
int		handle_infile(t_data *data, char *file);

void	ft_cd(t_data *data, char **tokens);
void	ft_pwd(t_data *data, char **tokens);
void	ft_echo(t_data *data, char **tokens);
void	ft_export(t_data *data, char **tokens);
void	ft_unset(t_data *data, char **tokens);
void	ft_env(t_data *data, char **tokens);
void	ft_exit(t_data *data, char **tokens);

#endif