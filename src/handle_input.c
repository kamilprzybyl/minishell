#include "../inc/minishell.h"

int	init(t_data *data)
{
	// handle_infile(data, data->args[0]);
	// handle_outfile(data, data->args[2]);
	
	data->here_doc = 0;
	data->redirections = 0;
	data->pipe = 0;
	return (0);
}

void	handle_input(t_data *data, char *input)
{
	int		i;
	
	parse(data, input);
	// init(data);
	// if (data->redirections)
	// {
	// 	dup2(data->infile, STDIN_FILENO);
	// 	dup2(data->outfile, STDOUT_FILENO);
	// }
	i = 0;
	// redirect(data, data->cmnds[i], i);
	// i++;
	while (i < data->n - 1)
	{
		redirect(data, data->cmnds[i], i);
		i++;
	}
	// dup2(STDOUT_FILENO, STDOUT_FILENO);
	exec_cmd(data, data->cmnds[data->n - 1]);
}

