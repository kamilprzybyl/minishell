#include "../inc/minishell.h"

int	init(t_data *data)
{
	// handle_infile(data, data->args[0]);
	// handle_outfile(data, data->args[2]);
	
	data->here_doc = 0;
	data->input_redirections = 0;
	data->output_redirections = 0;
	data->tmp_fd = 0;
	data->pipe = 0;
	return (0);
}

void	handle_input(t_data *data, char *input)
{
	int		i;
	
	i = 0;
	while (i < data->n - 1)
	{
		parse(data, input);
		init(data);
		redirections(data);
		exec_cmd(data);
		i++;
	}
}

