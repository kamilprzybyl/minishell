#include "../../inc/minishell.h"

static int	append(char *var)
{
	int		i;
	char	**tmp;

	tmp = malloc(sizeof(char *) * (ft_arrlen(g_env) + 1 + 1));
	if (!tmp)
		return (1);
	i = 0;
	while (g_env[i])
	{
		tmp[i] = ft_strdup(g_env[i]);
		i++;
	}
	tmp[i++] = ft_strdup(var);
	tmp[i] = NULL;
	free_arr(g_env);
	g_env = tmp;
	return (0);
}

static int	add(char *var)
{
	int		i;
	int		index;

	if (!ft_strrchr(var, '='))
		return (1);
	index = (int)(ft_strrchr(var, '=') - var);
	i = 0;
	while (g_env[i])
	{
		if (ft_strncmp(g_env[i], var, index + 1) == 0)
		{
			free(g_env[i]);
			g_env[i] = ft_strdup(var);
			return (0);
		}
		i++;
	}
	append(var);
	return (0);
}

void	ft_export(t_data *data)
{
	int	i;

	(void)data;
	i = 1;
	while (data->tokens[i])
	{
		if (add(data->tokens[i]) == 1)
			exit(1);
		i++;
	}
}
