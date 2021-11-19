#include "../../inc/minishell.h"

int	parse(t_data *data, char *input)
{
	int	i;

	data->args = ft_split(input, '|');
	data->n = ft_arrlen(data->args);
	data->cmnds = malloc(sizeof(char **) * (data->n + 1));
	i = 0;
	while (data->args[i])
	{
		data->cmnds[i] = ft_split(data->args[i], ' ');
		i++;
	}
	// for (int i = 0; data->cmnds[i]; i++)
	// {
	// 	for (int j = 0; data->cmnds[i][j]; j++)
	// 		printf("[%s]", data->cmnds[i][j]);
	// 	printf("\n");
	// }
	return (0);
}
