/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:00:47 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/01 18:02:04 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_getenv(t_data *data, char *name)
{
	int		index;
	int		len;
	int		i;

	if (name == NULL)
		return ("$");
	if (ft_strncmp(name, "?", 2) == 0)
	{
		return (ft_itoa(data->exit_val));
	}
	if (name[0] == '?')
		return (ft_itoa(data->exit_val));
	len = ft_strlen(name);
	i = 0;
	while (data->env[i] && ft_strncmp(name, data->env[i], len))
		i++;
	if (data->env[i] == NULL )
		return (NULL);
	index = ft_strchr(data->env[i], '=');
	return (&data->env[i][index + 1]);
}
