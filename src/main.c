#include "../inc/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_data	data;
	pid_t	pid;

	g_env = set_env(envp);
	while (1)
	{
		input = readline("minishell % ");
		add_history(input);
		pid = fork();
		if (pid < 0)
			exit(1);
		if (pid == 0)
			handle_input(&data, input);
		else
			wait(NULL);
	}
	return 0;
}