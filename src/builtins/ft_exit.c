/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:34:37 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/01 20:52:55 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	error_msg(t_data *data)
{
	ft_putstr_fd("minishell: exit: ", 2);
	if (ft_arrlen(data->all[3]) > 2)
		ft_putstr_fd("too many arguements\n", 2);
	else
	{
		ft_putstr_fd(data->all[3][1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
	}
}

int	ft_exit(t_data *data)
{
	int	exit_val;

	exit_val = 0;
	clear_history();
	free_matrix(data->env);
	close(data->tmp_stdin);
	close(data->tmp_stdout);
	ft_putstr_fd("exit\n", 2);
	if ((data->all[3][1] && !is_number(data->all[3][1]))
		|| ft_arrlen(data->all[3]) > 2)
	{
		error_msg(data);
		exit_val = 1;
	}
	if (data->all[3][1])
		exit_val = ft_atoi(data->all[3][1]);
	free_arr(data);
	exit(exit_val);
	return (0);
}
