#include "../../inc/minishell.h"

int	handle_outfile(t_data *data, char *file)
{
	int	len;

	len = ft_arrlen(data->args);
	if (data->here_doc)
		data->outfile = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		data->outfile = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->outfile == -1)
	{
		perror(file);
		close(data->infile);
		return (1);
	}
	return (0);
}
