#include "../../inc/minishell.h"

void	env(t_data *data, char **tokens)
{
	int	i;

	i = 0;
	while (g_env[i])
	{
		printf("%s\n", g_env[i]);
		i++;
	}
}
