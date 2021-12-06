/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:05:20 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/03 16:55:53 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data			data;

	set_env(&data, envp);
	data.all[3] = NULL;
	data.tmp_stdin = dup(STDIN_FILENO);
	data.tmp_stdout = dup(STDOUT_FILENO);
	while (1)
	{
		data.tmp_fd = dup(STDIN_FILENO);
		if (data.tmp_fd == -1)
			return (1);
		if (handle_input(&data))
			return (0);
		free(data.line);
		data.line = NULL;
		if (dup2(data.tmp_stdin, STDIN_FILENO) == -1)
			return (1);
	}
	return (0);
	(void)argc;
	(void)argv;
}
