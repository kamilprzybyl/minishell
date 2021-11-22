#include "../../inc/minishell.h"

void	redirections(t_data *data)
{
	if (data->input_redirections)
		dup2(data->infile, STDIN_FILENO);
	if (data->output_redirections)
		dup2(data->outfile, STDOUT_FILENO);
}
