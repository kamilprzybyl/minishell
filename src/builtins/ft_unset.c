#include "../../inc/minishell.h"

static int	delete(char *var)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = malloc(sizeof(char *) * ft_arrlen(g_env));
	if (!g_env)
		return (1);
	i = 0;
	j = 0;
	while (g_env[j])
	{
		if (ft_strncmp(g_env[i], var, ft_strlen(var)) == 0
			&& g_env[i][ft_strlen(var)] == '=')
			j++;
		tmp[i] = ft_strdup(g_env[j]);
		i++;
		j++;
	}
	free_arr(g_env);
	g_env = tmp;
	return (0);
}

void	ft_unset(t_data *data)
{
	int	i;

	(void)data;
	i = 0;
	while (data->tokens[i])
	{
		if (delete(data->tokens[i]) == 1)
			exit(1);
		i++;
	}
}
