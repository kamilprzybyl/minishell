#include "../../inc/minishell.h"

int	exec_bin(t_data *data)
{
	int		i;
	char	*cmd;
	char	**paths;

	i = 0;
	paths = ft_split(getenv("PATH"), ':');
	while (paths[i])
	{
		if (!data->tokens[0])
			write(2, "zsh: command not found: \n", 26);
		cmd = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = cmd;
		cmd = ft_strjoin(paths[i], data->tokens[0]);
		if (!cmd)
			exit(1);
		execve(cmd, data->tokens, g_env);
		free(cmd);
		i++;
	}
	ft_putstr_fd("zsh: command not found: ", 2);
	ft_putendl_fd(data->tokens[0], 2);
	free_arr(paths);
	free_arr(data->tokens);
	exit(1);
}
