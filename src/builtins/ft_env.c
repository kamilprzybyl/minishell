#include "../../inc/minishell.h"

void	ft_env(t_data *data, char **tokens)
{
	int	i;

	(void)data;
	(void)tokens;
	i = 0;
	while (g_env[i])
	{
		printf("%s\n", g_env[i]);
		i++;
	}
}
