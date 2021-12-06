/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:29:58 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/30 11:31:31 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_creatfilename(int *i, char **newname)
{
	while (*newname[(*i) + 1] && *newname[*i] == 'z')
	{
		newname[0][*i] = 'a';
		(*i)++;
		(newname[0][*i])++;
	}
}

char	*ft_getfilename(t_data *data, char *limiter, char **newname)
{
	char		*path;
	char		*filepath;
	int			len;
	struct stat	buffer;
	int			i;

	(void)data;
	filepath = NULL;
	path = ft_getenv(data, "TMPDIR");
	len = ft_strlen(limiter) + 1;
	*newname = (char *)ft_calloc(len + 1, sizeof(char));
	if (*newname == NULL)
		return (NULL);
	ft_memset(*newname, 'a', len);
	filepath = ft_strjoin(path, *newname);
	while (stat(filepath, &buffer) == 0 || stat(*newname, &buffer) == 0)
	{
		if (filepath != NULL)
			free(filepath);
		i = 0;
		*newname[i] += 1;
		ft_creatfilename(&i, newname);
		filepath = ft_strjoin(path, *newname);
	}
	return (filepath);
}
