#include "../../inc/minishell.h"

void	echo(t_data *data, char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		printf("%s", tokens[i]);
		i++;
	}
	printf("\n");
	return (0);
}
