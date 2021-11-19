#include "../../inc/minishell.h"

// int	pipe_redirection(int input_stream, int output_stream)
// {
// 	if (dup2(input_stream, STDIN_FILENO) == -1)
// 		return (1);
// 	if (dup2(output_stream, STDOUT_FILENO) == -1)
// 		return (1);
// 	return (0);
// }

void	redirect(t_data *data, char **tokens, __attribute__ ((unused)) int i)
{
	pid_t	pid;
	int		pipe_fd[2];

	printf("12\n");
	if (pipe(pipe_fd) == -1)
		exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		
		// close(pipe_fd[0]);
		// if (i < data->n - 1)
		// 	dup2(pipe_fd[1], STDOUT_FILENO);
		// else
		// 	dup2(STDOUT_FILENO, STDOUT_FILENO);
		// // if (i == 0)
		// // 	exit(1);
		// // else
		close(pipe_fd[0]);
		dup2(close(pipe_fd[1]), STDOUT_FILENO);
			// ft_perror("ERROR - 5");
		close(pipe_fd[1]);
		exec_cmd(data, tokens);
		// executer(cmd, envp);
	}
	else
	{
		// close(fd[1]);
		// if (dup2(fd[0], STDIN_FILENO) == -1)
		// 	ft_perror("ERROR - 6");
		// close(fd[0]);
		// waitpid(pid, NULL, 0);
		close(pipe_fd[1]);
		// if (i != 0)
		dup2(pipe_fd[0], STDIN_FILENO);
		// else
			// dup2(STDIN_FILENO, STDIN_FILENO);
		close(pipe_fd[0]);
		waitpid(pid, NULL, 0);
		// wait(NULL);
	}
}
