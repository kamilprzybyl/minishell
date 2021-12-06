/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:19:17 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/03 13:42:53 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//0 = redirect input; 1 = append mode;
//2 = redirect output; 3 = argv; 5 = NULL;
// out 0 = >> is last; 1 = > is last

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <termios.h>
# include <sys/stat.h>

# define MAX_PATH 4096

typedef struct s_data
{
	int				pipes;
	int				pip_index;
	int				tmp_stdin;
	int				tmp_stdout;
	int				here_doc_qot;
	int				fd[2];
	int				tmp_fd;
	char			*line;
	char			**all[5];
	int				out;
	int				pip_end;
	int				exit_val;
	int				pid_last;
	char			**env;
}			t_data;

typedef char	t_c;

typedef struct s_builtins
{
	t_c	*cmd;
	int (*f)(t_data	*data);
}	t_builtins;

int		set_env(t_data *data, char **envp);
void	parse(t_data *data);
void	handle_here_doc(t_data *data);
int		handle_signals(void);
int		handle_signal_in_exec(void);
void	handle_signals_here_doc(void);
void	sigfunc_inter(int sig);

int		handle_input(t_data *data);
int		handle_cmd(t_data *data);
int		check_input(char *line);

int		redirect(t_data *data);

int		exec_builtin(t_data *data);
void	exec_bin(t_data *data);

void	free_arr(t_data *data);
void	replace_env(t_data *data, char **word, int i);
char	*ft_getenv(t_data *data, char *name);
int		is_number(char *s);

int		ft_cd(t_data *data);
int		ft_pwd(t_data *data);
int		ft_echo(t_data *data);
int		ft_export(t_data *data);
int		ft_unset(t_data *data);
int		ft_env(t_data *data);
int		ft_exit(t_data *data);

#endif