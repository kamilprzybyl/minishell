#include "../../inc/minishell.h"

static char	**fetch_paths(t_data *data)
{
	char	*index;
	int		i;

	i = 0;
	while (ft_strncmp("PATH=", data->envp[i], 5))
		i++;
	index = ft_strchr(data->envp[i], '=');
	return (ft_split(index + 1, ':'));
}

int	exec_bin(t_data *data, char **tokens)
{
	int		i;
	char	*cmd;
	char	**paths;

	i = 0;
	paths = fetch_paths(data);
	while (paths[i])
	{
		if (!tokens[0])
			write(2, "zsh: command not found: \n", 26);
		cmd = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = cmd;
		cmd = ft_strjoin(paths[i], tokens[0]);
		if (!cmd)
			exit(1);
		execve(cmd, tokens, data->envp);
		free(cmd);
		i++;
	}
	ft_putstr_fd("zsh: command not found: ", 2);
	ft_putendl_fd(tokens[0], 2);
	free_arr(paths);
	free_arr(tokens);
	exit(1);
}
