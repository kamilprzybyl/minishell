#include "../../inc/minishell.h"

void	env(t_data *data, char **tokens)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		printf("%s\n", data->env[i]);
		i++;
	}
}
