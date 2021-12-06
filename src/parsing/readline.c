/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:51:11 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/29 15:45:35 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

int	check_input(char	*line)
{
	int		j;
	t_temp	temp1;
	char	*temp[4];

	j = 0;
	temp[0] = "<<<";
	temp[1] = "||";
	temp[2] = ">>>";
	ft_init_s_temp(&temp1);
	while (line != NULL && line[temp1.i] != '\0')
	{
		ft_qot_check(&temp1, line[temp1.i]);
		while (j < 3 && temp1.sqot == 1 && temp1.dqot == 1)
		{
			if (ft_strncmp(&line[temp1.i], temp[j], ft_strlen(temp[j])) == 0)
				return (1);
			j++;
		}
		j = 0;
		temp1.i++;
	}
	return (0);
}

void	parse(t_data *data)
{
	data->pip_end = 0;
	ft_save_redirections(data);
	ft_save_argv(data);
	ft_remove_qots_in_all(data);
}
