#include "../../inc/minishell.h"

int	handle_outfile(t_data *data)
{
	int	len;

	len = ft_arrlen(data->args);
	if (data->here_doc)
		data->outfile = open(data->args[len - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		data->outfile = open(data->args[len - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->outfile == -1)
	{
		perror(data->args[len - 1]);
		close(data->infile);
		return (1);
	}
	return (0);
}
