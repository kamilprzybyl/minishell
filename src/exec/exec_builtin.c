#include "../../inc/minishell.h"

t_builtins	cmd_list[] =
{
	{"echo", echo},
	{"pwd", pwd},
	{"exit", exit},
	{"cd", cd},
	{"env", env},
	{"export", export},
	{"unset", unset},
	{NULL, NULL}
};

int	exec_builtin(t_data *data, char **tokens)
{
	int	i;

	i = 0;
	while (cmd_list[i])
	{
		if (ft_strncmp(cmd_list[i].cmd, tokens[0], ft_strlen(tokens[0])) == 0)
		{
			cmd_list[i].f(data, tokens);
			return (1);
		}
		i++;
	}
	return (0);
}
