/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:40:25 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/01 20:40:26 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_arr(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free_matrix(data->all[i]);
		i++;
	}
}
