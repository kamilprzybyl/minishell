/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:54:54 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/03 12:03:34 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

void	ft_remove_qots(t_data *data, char **word, int i, t_temp *info)
{
	char	*temp[5];
	int		beg;
	int		j;
	int		*qot;

	j = -1;
	pointer_on_qot(info, &qot);
	temp[0] = word[i];
	beg = info->i;
	while (word[i][info->i++] && *qot != 1)
		ft_qot_check(info, word[i][info->i]);
	info->i--;
	temp[1] = ft_substr(word[i], 0, beg);
	temp[2] = ft_substr(word[i], beg + 1, info->i - beg - 1);
	if (&info->dqot == qot)
		replace_env(data, temp, 2);
	temp[3] = ft_strjoin(temp[1], temp[2]);
	temp[4] = ft_substr(word[i], info->i + 1, ft_strlen(&word[i][info->i + 1]));
	word[i] = ft_strjoin(temp[3], temp[4]);
	info->i = ft_strlen(word[i]) - ft_strlen(temp[4]) - 1;
	while (j++ < 4)
	{
		if (temp[j] != NULL)
			free(temp[j]);
	}
}

char	*ft_malloc_inside_qot(char *beg, int *w)
{
	t_temp	temp;

	ft_init_s_temp(&temp);
	if (ft_strchr(beg, ' ') == -1)
		temp.i = ft_strlen(beg);
	else
		temp.i = ft_strchr_out_of_qot(beg, ' ');
	if (temp.i > ft_strchr_out_of_qot(beg, '|'))
		temp.i = ft_strchr_out_of_qot(beg, '|');
	if (temp.i > ft_strchr_out_of_qot(beg, '<'))
		temp.i = ft_strchr_out_of_qot(beg, '<');
	if (temp.i > ft_strchr_out_of_qot(beg, '>'))
		temp.i = ft_strchr_out_of_qot(beg, '>');
	*w += temp.i ;
	return (ft_take_str_out(&beg[0], temp.i));
}

char	*ft_inside_qot(t_temp *temp, char *beg, int *w)
{
	int	*qot;
	int	j;

	j = 0;
	temp->i++;
	qot = NULL;
	pointer_on_qot(temp, &qot);
	while (beg[temp->i + j] != '\0')
	{
		ft_qot_check(temp, beg[temp->i + j]);
		if (*qot == 1)
		{
			*w += temp->i + j + 1;
			return (ft_take_str_out(&beg[temp->i - 1], j + 2));
		}
		j++;
	}
	return (NULL);
}

void	ft_indent_qots(t_data *data, char **word, int i)
{
	t_temp	temp1;

	if (word == NULL)
		return ;
	ft_init_s_temp(&temp1);
	while (word[i] && word[i][temp1.i])
	{
		ft_qot_check(&temp1, word[i][temp1.i]);
		if (temp1.sqot == -1)
		{
			ft_remove_qots(data, word, i, &temp1);
		}
		else if (temp1.dqot == -1)
		{
			replace_env(data, word, i);
			ft_remove_qots(data, word, i, &temp1);
		}
		else if (ft_strchr_out_of_qot(&word[i][temp1.i], '$')
			!= (int)ft_strlen(&word[i][temp1.i]))
			replace_env(data, word, i);
		temp1.sqot = 1;
		temp1.dqot = 1;
		temp1.i++;
	}
}

void	ft_remove_qots_in_all(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (data->all[j] != NULL && data->all[j][i])
		{
			ft_indent_qots(data, data->all[j], i);
			i++;
		}
		j++;
	}
}
