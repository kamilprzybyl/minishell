#include "../inc/minishell.h"

void	exec_cmd(t_data *data, char **tokens)
{
	if (exec_builtin(&data, tokens) == 1)
		exec_bin(&data, tokens);
}

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

	if (pipe(data->pipe_fd) == -1)
		exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		close(data->pipe_fd[0]);
		dup2(data->pipe_fd[1], STDOUT_FILENO);
		exec_cmd(data, tokens);
	}
	else
	{
		close(data->pipe_fd[1]);
		dup2(data->pipe_fd[0], STDIN_FILENO);
		wait(NULL);
		// close(pipe_fd[1]);
		// close(tmp_fd);
		// dup2(pipe_fd[0], tmp_fd);
		// close(pipe_fd[0]);
	}
}

void	handle_input(t_data *data)
{
	int		i;
	
	i = 0;
	if (redirections)
	{
		dup2(data->infile, STDIN_FILENO);
		dup2(data->outfile, STDOUT_FILENO);
	}
	while (not the last command)
	{
		redirect();
		exec_cmd(data, tokens);
		i++;
	}
	exec_cmd(data, tokens);
}

