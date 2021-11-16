#include "../../inc/minishell.h"

static int	append(t_data *data, char *var)
{
	int		i;
	char	**tmp;

	tmp = malloc(sizeof(char *) * (ft_arrlen(data->env) + 1 + 1));
	if (!tmp)
		return (1);
	i = 0;
	while (data->env[i])
	{
		tmp[i] = ft_strdup(data->env[i]);
		i++;
	}
	tmp[i++] = ft_strdup(var);
	tmp[i] = NULL;
	data->env = tmp;
	return (0);
}

static int	add(t_data *data, char **tokens)
{
	int		i;
	int		index;

	if (!ft_strrchr(var, '='))
		return (1);
	index = (int)(ft_strrchr(var, '=') - var);
	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], var, index + 1) == 0)
		{
			free(data->env[i]);
			data->env[i] = ft_strdup(var);
			return (0);
		}
		i++;
	}
	append(data, var);
	return (0);
}

int	export(t_data *data, char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (add(data, tokens[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
