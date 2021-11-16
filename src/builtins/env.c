#include "../../inc/minishell.h"

int	set_env(t_data *data, char **envp)
{
	int	i;

	data->env = malloc(sizeof(char *) * (ft_arrlen(envp) + 1));
	if (!data->env)
		return (1);
	i = 0;
	while (envp[i])
	{
		data->env[i] = ft_strdup(envp[i]);
		i++;
	}
	data->env[i] = NULL;
	return (0);
}

int	unset(t_data *data, char *var)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = malloc(sizeof(char *) * ft_arrlen(data->env));
	if (!data->env)
		return (1);
	i = 0;
	j = 0;
	while (data->env[j])
	{
		if (ft_strncmp(data->env[i], var, ft_strlen(var)) == 0
			&& data->env[i][ft_strlen(var)] == '=')
			j++;
		tmp[i] = ft_strdup(data->env[j]);
		i++;
		j++;
	}
	free_arr(data->env);
	data->env = tmp;
	return (0);
}

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

int	export(t_data *data, char *var)
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

void	env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		printf("%s\n", data->env[i]);
		i++;
	}
}
