/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:01:46 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/03 16:40:17 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

static char	*ft_get_herdoc_line(void)
{
	struct termios	termios_p;
	char			*inpt;

	tcgetattr(STDOUT_FILENO, &termios_p);
	handle_signals_here_doc();
	termios_p.c_lflag &= ~ECHOCTL;
	tcsetattr(STDOUT_FILENO, 0, &termios_p);
	inpt = readline("heredoc> ");
	termios_p.c_lflag |= ECHOCTL;
	tcsetattr(STDOUT_FILENO, 0, &termios_p);
	return (inpt);
}

static void	read_here_doc(t_data *data, char *limiter, int fd)
{
	char			*inpt;
	int				i;

	while (1)
	{
		inpt = ft_get_herdoc_line();
		if (inpt == NULL
			|| ft_strncmp(limiter, inpt, ft_strlen(limiter) + 1) == 0)
		{
			if (inpt == NULL)
				data->exit_val = 1;
			else
				data->exit_val = 0;
			break ;
		}
		i = -1;
		if (data->here_doc_qot == 0)
			replace_env(data, &inpt, 0);
		write(fd, inpt, ft_strlen(inpt));
		write(fd, "\n", 1);
		free(inpt);
	}
	handle_signal_in_exec();
	dup2(data->tmp_stdin, STDIN_FILENO);
	free(inpt);
}

static void	here_doc(t_data *data, char *limiter, char *filepath)
{
	int		fd;

	fd = open(filepath, O_EXCL | O_CREAT | O_WRONLY | O_TRUNC, 0644);
	free(filepath);
	if (fd < 0)
	{
		perror("here_doc");
		return ;
	}
	read_here_doc(data, limiter, fd);
	close(fd);
}

static void	ft_get_delimiter(t_temp	*temp, t_data *data)
{
	char	*limiter;
	char	*filename;
	char	*limiterqots;
	int		beg;
	int		i;

	filename = NULL;
	beg = temp->i + 1;
	temp->i += 2;
	while (data->line[temp->i] == ' ')
		temp->i++;
	limiter = ft_malloc_inside_qot(&data->line[temp->i], &temp->i);
	if (!limiter)
		return ;
	limiterqots = limiter;
	ft_indent_qots(data, &limiter, 0);
	data->here_doc_qot = 0;
	if (ft_strncmp(limiterqots, limiter, ft_strlen(limiter)) != 0)
		data->here_doc_qot = 1;
	here_doc(data, limiter, ft_getfilename(data, limiter, &filename));
	i = -1;
	while (filename[++i])
		data->line[beg + i] = filename[i];
	free(filename);
	free(limiter);
}

void	handle_here_doc(t_data *data)
{
	t_temp	temp;

	ft_init_s_temp(&temp);
	while (data->line[temp.i])
	{
		ft_qot_check(&temp, data->line[temp.i]);
		if (temp.sqot == 1 && temp.dqot == 1
			&& ft_strncmp(&data->line[temp.i], "<<", 2) == 0)
		{
			ft_get_delimiter(&temp, data);
			temp.i--;
		}
		if (data->line[temp.i] != '\0')
			temp.i++;
	}
}
