/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:36:36 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/02 17:02:23 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static const t_builtins	g_cmd_list[] =
{
	{"echo", ft_echo},
	{"pwd", ft_pwd},
	{"exit", ft_exit},
	{"cd", ft_cd},
	{"env", ft_env},
	{"export", ft_export},
	{"unset", ft_unset},
	{NULL, NULL}
};

int	exec_builtin(t_data *data)
{
	int		i;
	char	**argv;

	argv = data->all[3];
	i = 0;
	while (g_cmd_list[i].cmd)
	{
		if (argv[0] && ft_strncmp(g_cmd_list[i].cmd, argv[0],
				ft_strlen(argv[0]) + 1) == 0)
		{
			redirect(data);
			g_cmd_list[i].f(data);
			dup2(data->tmp_stdin, STDIN_FILENO);
			dup2(data->tmp_stdout, STDOUT_FILENO);
			free_arr(data);
			return (0);
		}
		i++;
	}
	return (1);
}
