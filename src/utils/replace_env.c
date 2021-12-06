/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:01:15 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/03 16:59:39 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*append(char *word, char a)
{
	char	*temp;
	int		len;

	if (word != NULL)
		len = ft_strlen(word);
	else
		len = 0;
	temp = (char *)ft_calloc(len + 2, sizeof(char));
	if (temp == NULL)
		return (NULL);
	if (word != NULL)
		ft_memcpy(temp, word, len);
	if (word != NULL)
		free(word);
	temp[len] = a;
	return (temp);
}

char	*replace_env_to_value(t_data *data, char *word, int *j, char *temp)
{
	char	*temp1;
	char	*temp2;
	char	*temp3;
	int		k;

	temp1 = NULL;
	k = 1;
	while (word[*j + k] && (ft_isalpha(word[*j + k]) || word[*j + k] == '?'))
	{
		temp1 = append(temp1, word[*j + k]);
		k++;
	}
	temp2 = temp;
	temp3 = ft_getenv(data, temp1);
	if (temp3 != NULL)
		temp = ft_strjoin(temp, temp3);
	if (temp1 && temp1[0] == '?')
		free (temp3);
	if (temp2 != NULL)
		free(temp2);
	if (temp1 != NULL)
		free(temp1);
	*j = *j + k;
	return (temp);
}

void	replace_env(t_data *data, char **word, int i)
{
	int		j;
	char	*temp;

	j = 0;
	temp = NULL;
	if (ft_strchr(word[i], '$') != -1)
	{
		while (word[i][j])
		{
			if (word[i][j] == '$')
				temp = replace_env_to_value(data, word[i], &j, temp);
			if (word[i][j] == '\0')
				break ;
			else
				temp = append(temp, word[i][j]);
			j++;
		}
		if (word[i] != NULL)
			free(word[i]);
		word[i] = temp;
	}
}
