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
int		len(char **arr);
void	env(t_data *data);
int		set_env(t_data *data, char **envp);
int		export(t_data *data, char *var);
int		unset(t_data *data, char *var);
void	free_arr(char **arr);
int		export(t_data *data, char *var);

#endif