/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_here_doc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:45:10 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/01 14:27:56 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	sigfunc_here_doc(int sig)
{
	sigfunc_inter(sig);
	close(STDIN_FILENO);
}

void	handle_signals_here_doc(void)
{
	signal(SIGINT, sigfunc_here_doc);
}
