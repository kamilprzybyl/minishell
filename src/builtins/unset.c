#include "../../inc/minishell.h"

static void	delete(t_data *data, char *var)
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

int	unset(t_data *data, char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (delete(data, tokens[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
