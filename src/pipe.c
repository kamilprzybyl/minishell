#include "../inc/minishell.h"

void	handle_child(t_data *data, int tmp_fd, int i, int *pipe_fd)
{
	char	**tokens;

	tokens = ft_split(data->args[i], ' ');
	// dup2(tmp_fd, STDIN_FILENO);
	// if (i == data->n - 2)
	// 	dup2(data->outfile, STDOUT_FILENO);
	// else
	// 	dup2(pipe_fd[1], STDOUT_FILENO);
	if (exec_builtin(&data, tokens) == 1)
		exec_bin(&data, tokens);
}

void	pipex(t_data *data)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		tmp_fd;
	int		i;

	// if (data->here_doc)
	// 	i = 2;
	// else
		i = 1;
	tmp_fd = data->infile;
	// while (i < data->n - 1)
	// {
		if (pipe(pipe_fd) == -1)
			exit(1);
		pid = fork();
		if (pid < 0)
			exit(1);
		else if (pid == 0)
			handle_child(data, tmp_fd, i, pipe_fd);
		else
		{
			waitpid(-1, NULL, 0);
			close(pipe_fd[1]);
			// close(tmp_fd);
			// dup2(pipe_fd[0], tmp_fd);
			close(pipe_fd[0]);
	// 	}
	// 	i++;
	// }
}
