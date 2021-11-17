#include "../../inc/minishell.h"

int	pipe_redirection(t_data *data, int input_stream, int output_stream)
{
	if (dup2(input_stream, STDIN_FILENO) == -1)
		return (1);
	if (dup2(output_stream, STDOUT_FILENO) == -1)
		return (1);
	return (0);
}

void	redirect(t_data *data)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		exec_cmd(data, tokens);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		wait(NULL);
		// close(pipe_fd[1]);
		// close(tmp_fd);
		// dup2(pipe_fd[0], tmp_fd);
		// close(pipe_fd[0]);
	}
}
