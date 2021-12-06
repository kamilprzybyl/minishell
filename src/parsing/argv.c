/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:46:51 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/02 12:52:48 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

int	ft_count_argc(t_data *data)
{
	t_temp	temp;
	int		argc;

	argc = 0;
	ft_init_s_temp(&temp);
	while (data->line[temp.i]
		&& (data->line[temp.i] != '|' || temp.sqot == -1 || temp.dqot == -1))
	{
		ft_qot_check(&temp, data->line[temp.i]);
		if (temp.dqot == -1 && temp.sqot == -1)
			ft_qot_check(&temp, data->line[temp.i]);
		if (data->line[temp.i] != ' '
			&& (data->line[temp.i + 1] == ' '
				|| data->line[temp.i + 1] == '\0'
				|| data->line[temp.i + 1] == '|')
			&& ((temp.sqot == 1 && temp.dqot == 1)
				|| data->line[temp.i + 1] == '\0'))
			argc++;
		temp.i++;
	}
	return (argc);
}

void	ft_get_word(t_data *data, t_temp *temp, int *argc)
{
	while (data->line[temp->i] != '\0' && data->line[temp->i] != '|')
	{
		ft_qot_check(temp, data->line[temp->i]);
		if (data->line[temp->i] && data->line[temp->i] != ' ')
		{
			data->all[3][*argc]
				 = ft_malloc_inside_qot(&data->line[temp->i], &temp->i);
			if (data->all[3][*argc] == NULL)
				break ;
			(*argc)++;
		}
		if (data->line[temp->i] != '\0'
			&& data->line[temp->i] != '|'
			&& data->line[temp->i] != '\'')
			temp->i++;
	}
}

void	ft_save_argv(t_data *data)
{
	t_temp	temp;
	int		argc;

	data->all[3] = NULL;
	ft_init_s_temp(&temp);
	argc = ft_count_argc(data);
	if (argc == 0)
		return ;
	data->all[3] = (char **)ft_calloc(argc + 1, sizeof(char *));
	if (!data->all[3])
		return ;
	data->all[3][argc] = NULL;
	argc = 0;
	while (data->line[temp.i] && data->line[temp.i] != '|')
	{
		if (data->line[temp.i] != ' ')
			ft_get_word(data, &temp, &argc);
		if (data->line[temp.i] != '\0' && data->line[temp.i] != '|')
			temp.i++;
	}
	if (data->line[temp.i] == '|')
	{
		data->pip_end = 1;
		data->line[temp.i] = ' ';
	}
}
