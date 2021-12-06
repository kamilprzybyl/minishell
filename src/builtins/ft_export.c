/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:34:56 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/27 22:35:13 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	free_matrix(data->env);
	data->env = tmp;
	return (0);
}

static int	add(t_data *data, char *var)
{
	int		i;
	int		index;

	if (ft_strchr(var, '=') < 0)
		return (1);
	index = ft_strchr(var, '=');
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

int	ft_export(t_data *data)
{
	int		i;
	char	**argv;

	argv = data->all[3];
	i = 1;
	while (argv[i])
	{
		add(data, argv[i]);
		i++;
	}
	return (0);
}
