/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:35:36 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/27 22:35:51 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	delete(t_data *data, char *var)
{
	int		i;
	int		j;
	char	**tmp;

	if (!data->env || !ft_getenv(data, var))
		return (1);
	tmp = malloc(sizeof(char *) * ft_arrlen(data->env));
	if (!tmp)
		return (1);
	i = 0;
	j = 0;
	while (data->env[j])
	{
		if (ft_strncmp(data->env[i], var, ft_strlen(var)) == 0
			&& data->env[i][ft_strlen(var)] == '=')
			j++;
		if (data->env[j])
		{
			tmp[i++] = ft_strdup(data->env[j]);
			j++;
		}
	}
	tmp[i] = NULL;
	free_matrix(data->env);
	data->env = tmp;
	return (0);
}

int	ft_unset(t_data *data)
{
	int		i;
	char	**argv;

	argv = data->all[3];
	i = 1;
	while (argv[i])
	{
		delete(data, argv[i]);
		i++;
	}
	return (0);
}
