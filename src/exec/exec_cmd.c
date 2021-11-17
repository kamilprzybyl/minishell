#include "../../inc/minishell.h"

void	exec_cmd(t_data *data, char **tokens)
{
	if (exec_builtin(data, tokens) == 1)
		exec_bin(tokens);
}
