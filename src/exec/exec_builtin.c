#include "../../inc/minishell.h"

t_builtins	cmd_list[] =
{
	{"echo", ft_echo},
	{"pwd", ft_pwd},
	{"exit", ft_exit},
	{"cd", ft_cd},
	{"env", ft_env},
	{"export", ft_export},
	{"unset", ft_unset},
	{NULL, NULL}
};

int	exec_builtin(t_data *data, char **tokens)
{
	int	i;

	i = 0;
	while (cmd_list[i].cmd)
	{
		if (ft_strncmp(cmd_list[i].cmd, tokens[0], ft_strlen(tokens[0])) == 0)
		{
			cmd_list[i].f(data, tokens);
			return (0);
		}
		i++;
	}
	return (1);
}
