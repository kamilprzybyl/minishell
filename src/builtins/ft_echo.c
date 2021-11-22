#include "../../inc/minishell.h"

void	ft_echo(t_data *data)
{
	int	i;

	(void)data;
	i = 1;
	while (tokens[i])
	{
		printf("%s", tokens[i]);
		i++;
	}
	printf("\n");
}
