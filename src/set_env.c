#include "../inc/minishell.h"

int	set_env(char **envp)
{
	int	i;

	g_env = malloc(sizeof(char *) * (ft_arrlen(envp) + 1));
	if (!g_env)
		return (1);
	i = 0;
	while (envp[i])
	{
		g_env[i] = ft_strdup(envp[i]);
		i++;
	}
	g_env[i] = NULL;
	return (0);
}
