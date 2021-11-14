#ifndef MINISHELL_H
# define MINISHELL_H

#include "../Libft/inc/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
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
}				t_data;

void	pipex(t_data *data);

#endif