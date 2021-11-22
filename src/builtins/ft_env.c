#include "../../inc/minishell.h"

void	ft_env(t_data *data)
{
	int	i;

	(void)data;
	i = 0;
	while (g_env[i])
	{
		printf("%s\n", g_env[i]);
		i++;
	}
}
