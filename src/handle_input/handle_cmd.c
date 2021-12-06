/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:09:44 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/03 14:09:50 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	child(t_data *data)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (redirect(data))
		exit(1);
	if (data->pip_end)
	{
		close(data->fd[0]);
		close(data->fd[1]);
	}
	close(data->tmp_fd);
	if (exec_builtin(data) == 1)
		exec_bin(data);
	else
		exit(0);
}

static void	parent(t_data *data)
{
	if (data->pip_end)
	{
		close(data->fd[1]);
		close(data->tmp_fd);
		data->tmp_fd = dup(data->fd[0]);
		close(data->fd[0]);
	}
	free_arr(data);
}

int	handle_cmd(t_data *data)
{
	if (data->pip_end && pipe(data->fd) == -1)
	{
		free_arr(data);
		return (1);
	}
	data->pid_last = fork();
	if (data->pid_last == -1)
		free_arr(data);
	else if (data->pid_last == 0)
		child(data);
	else
		parent(data);
	return (0);
}
