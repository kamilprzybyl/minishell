/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:40:46 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/01 20:40:49 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

void	ft_qot_check(t_temp *temp, char c)
{
	if (c == '\'')
		temp->sqot *= -1;
	else if (c == '\"')
		temp->dqot *= -1;
}

char	*ft_take_str_out(char *beg, int	i)
{
	char	*temp;

	temp = ft_substr(beg, 0, i);
	ft_memset(beg, ' ', i);
	return (temp);
}

void	ft_init_s_temp(t_temp *temp)
{
	temp->i = 0;
	temp->dqot = 1;
	temp->sqot = 1;
}
