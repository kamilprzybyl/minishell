/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:00:18 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/02 12:43:56 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void	sigfunc_inter(int sig)
{
	if (sig == SIGINT)
		write(1, "\n", 3);
	rl_on_new_line();
}

int	handle_signal_in_exec(void)
{
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		return (1);
	return (0);
}

void	sigfunc(int sig)
{
	sigfunc_inter(sig);
	rl_replace_line("", 0);
	rl_redisplay();
	return ;
}

int	handle_signals(void)
{
	if (signal(SIGINT, sigfunc) == SIG_ERR)
		return (1);
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (1);
	return (0);
}
