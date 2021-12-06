/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:56:49 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/03 16:59:17 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	child_sig_ret(t_data *data, int temp)
{
	if (WTERMSIG(temp) == SIGINT)
		ft_putstr_fd("\n", 2);
	else if (WTERMSIG(temp) == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", 2);
	data->exit_val = WTERMSIG(temp) + 128;
}

static void	wait_vor_child(t_data *data)
{
	int	temp;
	int	pid;

	temp = 0;
	pid = 0;
	while (pid != -1)
	{
		pid = wait(&temp);
		if (pid == data->pid_last)
		{
			if (WIFSIGNALED(temp))
			{
				child_sig_ret(data, temp);
				break ;
			}
			if (WIFEXITED(temp))
				WEXITSTATUS(temp);
			if (temp == 256)
				temp -= 129;
			else if (temp > 255)
				temp = temp % 255;
			data->exit_val = temp;
		}
	}
}

static void	handle_line(t_data *data)
{
	data->pip_index = 0;
	data->pipes = 0;
	handle_here_doc(data);
	while (data->pip_end == 1)
	{
		parse(data);
		if (data->pip_end == 0 && data->pip_index == 0 && data->all[3] != NULL)
			if (exec_builtin(data) == 0)
				break ;
		if (handle_cmd(data))
			return ;
		data->pip_index++;
	}
	close(data->tmp_fd);
	wait_vor_child(data);
}

static char	*get_line(void)
{
	struct termios	termios_p;
	char			*temp;

	tcgetattr(STDOUT_FILENO, &termios_p);
	if (handle_signals())
		return (NULL);
	termios_p.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDOUT_FILENO, 0, &termios_p) == -1)
		return (NULL);
	temp = readline("> ");
	if (handle_signal_in_exec())
	{
		if (temp != NULL)
			free(temp);
		return (NULL);
	}
	termios_p.c_lflag |= ECHOCTL;
	if (tcsetattr(STDOUT_FILENO, 0, &termios_p) == -1)
	{
		if (temp != NULL)
			free(temp);
		return (NULL);
	}
	return (temp);
}

int	handle_input(t_data *data)
{
	data->line = get_line();
	if (data->line == NULL)
	{
		close(data->tmp_stdin);
		close(data->tmp_stdout);
		clear_history();
		ft_putstr_fd("exit\n", 2);
		return (1);
	}
	if (check_input(data->line))
	{
		ft_putstr_fd("syntax error\n", 2);
		data->exit_val = 258;
	}
	else if (data->line[0] != '\0')
	{
		add_history(data->line);
		data->pip_end = 1;
		handle_line(data);
	}
	return (0);
}
