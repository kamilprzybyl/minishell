/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:51:52 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/02 12:54:15 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

int	ft_look_last(t_data *data, char *s1, char *s2)
{
	t_temp	temp;
	int		ret;

	ft_init_s_temp(&temp);
	ret = -1;
	while (data->line[temp.i] && data->line[temp.i] != '|')
	{
		ft_qot_check(&temp, data->line[temp.i]);
		if (temp.sqot == 1 && temp.dqot == 1
			 && ft_strncmp(&data->line[temp.i], s1, ft_strlen(s1)) == 0)
		{
			ret = 0;
			temp.i++;
		}
		else if (temp.sqot == 1 && temp.dqot == 1
			 && ft_strncmp(&data->line[temp.i], s2, ft_strlen(s2)) == 0)
			ret = 1;
		temp.i++;
	}
	return (ret);
}

int	ft_count_redir(t_data *data, char *c)
{
	int		count;
	t_temp	temp;

	count = 0;
	ft_init_s_temp(&temp);
	while (data->line[temp.i] && data->line[temp.i] != '|')
	{
		ft_qot_check(&temp, data->line[temp.i]);
		if (temp.sqot == 1 && temp.dqot == 1
			 && ft_strncmp(&data->line[temp.i], c, ft_strlen(c)) == 0)
			count++;
		temp.i++;
	}
	return (count);
}

static void	ft_skipp_to_beginn(t_data *data, int len, t_temp *temp, char **red)
{
	ft_memset(&data->line[temp->i], ' ', len);
	temp->i += len;
	while (data->line[temp->i] == ' ')
		temp->i++;
	*red = ft_malloc_inside_qot(&data->line[temp->i], &temp->i);
}

void	ft_save_redirection(t_data *data, char *c, char ***redirect)
{
	t_temp	temp;
	int		redir_count;

	redir_count = ft_count_redir(data, c);
	if (redir_count == 0)
		return ;
	ft_init_s_temp(&temp);
	*redirect = (char **)ft_calloc(redir_count + 1, sizeof(char *));
	if (*redirect == NULL)
		return ;
	(*redirect)[redir_count] = NULL;
	redir_count = 0;
	while (data->line[temp.i] && data->line[temp.i] != '|' && *redirect != NULL)
	{
		ft_qot_check(&temp, data->line[temp.i]);
		if (temp.sqot == 1 && temp.dqot == 1
			&& ft_strncmp(&data->line[temp.i], c, ft_strlen(c)) == 0)
		{
			ft_skipp_to_beginn(data, ft_strlen(c),
				&temp, &(*redirect)[redir_count++]);
			temp.i--;
		}
		if (data->line[temp.i] != '\0' && data->line[temp.i] != '|')
			temp.i++;
	}
}

void	ft_save_redirections(t_data *data)
{
	int		i;
	char	*temp[3];

	i = 0;
	temp[0] = "<";
	temp[1] = ">>";
	temp[2] = ">";
	data->out = -1;
	data->out = ft_look_last(data, temp[1], temp[2]);
	while (i < 3)
	{
		data->all[i] = NULL;
		ft_save_redirection(data, temp[i], &data->all[i]);
		i++;
	}
}
