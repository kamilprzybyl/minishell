/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:33:55 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/02 16:14:09 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_echo(t_data *data)
{
	int		i;
	int		is_n;
	char	**argv;

	argv = data->all[3];
	is_n = 0;
	i = 1;
	if (argv[1] && !ft_strncmp(argv[1], "-n", 3))
	{
		is_n = 1;
		i++;
	}
	while (argv[i] && ft_strncmp(argv[i], "-n", 3) == 0)
		i++;
	while (argv[i])
	{
		printf("%s", argv[i]);
		i++;
		if (argv[i])
			printf(" ");
	}
	if (!is_n)
		printf("\n");
	data->exit_val = 0;
	return (0);
}
