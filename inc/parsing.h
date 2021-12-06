/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:57:37 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/29 11:24:31 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

typedef struct s_temp
{
	int	i;
	int	sqot;
	int	dqot;
}				t_temp;

void	ft_qot_check(t_temp *temp, char c);
char	*ft_take_str_out(char *beg, int	i);
void	ft_init_s_temp(t_temp *temp);
char	*ft_apend(char *word, char a);
int		ft_count_argc(t_data *data);
void	ft_get_word(t_data *data, t_temp *temp, int *argc);
int		ft_look_last(t_data *data, char *s1, char *s2);
char	*ft_malloc_inside_qot(char *beg, int *w);
void	ft_indent_qots(t_data *data, char **word, int i);
void	ft_save_argv(t_data *data);
void	ft_save_redirections(t_data *data);
void	ft_remove_qots_in_all(t_data *data);
void	ft_remove_qots(t_data *data, char **word, int i, t_temp *info);
char	*ft_getfilename(t_data *data, char *limiter, char **newname);
int		ft_strchr_out_of_qot(char *beg, char c);
void	pointer_on_qot(t_temp *temp, int **qot);

#endif