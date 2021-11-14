#include "../inc/minishell.h"

int	arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static int	init(t_data *data, char *inpt)
{
	data->args = ft_split(inpt, ' ');
	data->n = arrlen(data->args);
	data->here_doc = 0;
	return (0);
}

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

static int	handle_infile(t_data *data)
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

static int	handle_outfile(t_data *data)
{
	if (data->here_doc)
		data->outfile = open(data->args[data->n - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		data->outfile = open(data->args[data->n - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->outfile == -1)
	{
		perror(data->argv[data->argc - 1]);
		close(data->infile);
		return (1);
	}
	return (0);
}

int	handle_input(t_data *data, char *inpt)
{
	init(data, inpt);
	for (int i = 0; i < data->n; i++)
		printf("arr[%d] = {%s}\n", i, data->args[i]);
	handle_infile(data);
	handle_outfile(data);
	pipex(data);
	close(data->outfile);
	return (0);
}

static int	init_2(t_data *data, int argc, char **argv, char **envp)
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*inpt;
	t_data	data;
	pid_t	pid;

	if (init_2(&data, argc, argv, envp) != 0)
		return (1);
	while (1)
	{
		inpt = readline("minishell % ");
		add_history(inpt);
		pid = fork();
		if (pid < 0)
			exit(1);
		if (pid == 0)
			handle_input(&data, inpt);
		else
			waitpid(-1, NULL, 0);
	}
	return 0;
}