#include "../../inc/minishell.h"

static int	here_doc(t_data *data, char *limiter)
{
	int		fd;
	char	*inpt;

	fd = open("tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		perror("here_doc");
	while (1)
	{
		inpt = readline("heredoc> ");
		if (ft_strncmp(limiter, inpt, ft_strlen(limiter) + 1) == 0)
			break ;
		write(fd, inpt, ft_strlen(inpt) + 1);
		write(fd, "\n", 1);
		free(inpt);
	}
	free(inpt);
	close(fd);
	data->infile = open("tmp", O_RDONLY);
	if (data->infile < 0)
		perror("here_doc");
	return (0);
}

int	handle_infile(t_data *data)
{
	if (ft_strncmp(data->args[0], "here_doc", 8) == 0)
	{
		here_doc(data, data->args[1]);
		data->here_doc = 1;
	}
	else
	{
		data->infile = open(data->args[0], O_RDONLY);
		if (data->infile == -1)
		{
			perror(data->args[0]);
			return (1);
		}
	}
	return (0);
}
