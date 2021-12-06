/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:42:44 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/27 22:45:26 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

int	ft_strchr_out_of_qot(char *beg, char c)
{
	t_temp	temp;

	ft_init_s_temp(&temp);
	while (beg[temp.i] && (beg[temp.i] != c
			|| (temp.sqot == -1 || temp.dqot == -1)))
	{
		ft_qot_check(&temp, beg[temp.i]);
		temp.i++;
	}
	return (temp.i);
}

void	pointer_on_qot(t_temp *temp, int **qot)
{
	if (temp->sqot > temp->dqot)
		*qot = &temp->dqot;
	else
		*qot = &temp->sqot;
}
