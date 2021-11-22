#include "../../inc/minishell.h"

void	child(t_data *data)
{
	dup2(data->tmp_fd, STDIN_FILENO);
	// if (i == data->argc - 2)
	// 	dup2(data->outfile, STDOUT_FILENO);
	if (data->pipe)
		dup2(data->pipe_fd[1], STDOUT_FILENO);
	// if (exec_builtin(data) == 1)
	exec_bin(data);
}

void	parent(t_data *data)
{
	waitpid(-1, NULL, 0);
	close(data->pipe_fd[1]);
	close(data->tmp_fd);
	dup2(data->pipe_fd[0], data->tmp_fd);
	close(data->pipe_fd[0]);
}

void	exec_cmd(t_data *data)
{
	pid_t	pid;

	if (pipe(data->pipe_fd) == -1)
		exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
		child(data);
	else
		parent(data);
}
