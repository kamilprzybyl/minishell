#include "../inc/minishell.h"

int	init(t_data *data)
{
	handle_infile(data);
	handle_outfile(data);
	data->here_doc = 0;
	return (0);
}

void	handle_input(t_data *data, char **input)
{
	int		i;
	
	i = 0;
	parse(data, input);
	init(data);
	if (data->redirections)
	{
		dup2(data->infile, STDIN_FILENO);
		dup2(data->outfile, STDOUT_FILENO);
	}
	while (data->pipe)
	{
		redirect(data);
		i++;
	}
	exec_cmd(data, tokens);
}

