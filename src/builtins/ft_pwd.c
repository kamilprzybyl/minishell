/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:35:22 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/27 22:35:24 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_pwd(__attribute__ ((unused)) t_data *data)
{
	char	cwd[MAX_PATH];

	if (getcwd(cwd, MAX_PATH) == NULL)
	{
		perror("minishell: pwd");
		return (1);
	}
	else
		printf("%s\n", cwd);
	return (0);
}
