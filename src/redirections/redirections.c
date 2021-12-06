/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:45:43 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/27 22:59:46 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	redirect_in_file(t_data *data, char **filepath, int *i)
{
	int		ifd;

	*filepath = ft_strjoin(ft_getenv(data, "TMPDIR"), data->all[0][*i]);
	ifd = open(*filepath, O_RDONLY);
	unlink(*filepath);
	free(*filepath);
	if (ifd < 0)
	{
		perror(data->all[0][*i]);
		return (-1);
	}
	return (ifd);
}

static int	redirect_in(t_data *data)
{
	int		i;
	int		ifd;
	char	*filepath;

	i = 0;
	ifd = 0;
	dup2(data->tmp_fd, STDIN_FILENO);
	while (data->all[0] && data->all[0][i])
	{
		ifd = open(data->all[0][i], O_RDONLY);
		if (ifd < 0)
			ifd = redirect_in_file(data, &filepath, &i);
		if (ifd == -1)
			return (1);
		if (dup2(ifd, STDIN_FILENO) == -1)
		{
			perror("dup2");
			close(ifd);
			return (1);
		}
		close(ifd);
		i++;
	}
	return (0);
}

int	redirect_out_append(t_data *data)
{
	int	i;
	int	ofd;

	i = 0;
	while (data->all[1] && data->all[1][i])
	{
		ofd = open(data->all[1][i], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (ofd == -1)
		{
			perror(data->all[1][i]);
			return (1);
		}
		if (data->out == 0)
			dup2(ofd, STDOUT_FILENO);
		close(ofd);
		i++;
	}
	return (0);
}

static int	redirect_out(t_data *data)
{
	int	i;
	int	ofd;

	i = 0;
	if (data->pip_end)
		dup2(data->fd[1], STDOUT_FILENO);
	while (data->all[2] && data->all[2][i])
	{
		ofd = open(data->all[2][i], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (ofd == -1)
		{
			perror(data->all[2][i]);
			return (1);
		}
		if (data->out == 1)
			dup2(ofd, STDOUT_FILENO);
		close(ofd);
		i++;
	}
	if (redirect_out_append(data))
		return (1);
	return (0);
}

int	redirect(t_data *data)
{
	if (redirect_in(data))
		return (1);
	if (redirect_out(data))
		return (1);
	return (0);
}
