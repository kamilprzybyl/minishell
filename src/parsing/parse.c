#include "../../inc/minishell.h"

int	parse(t_data *data, char *input)
{
	data->args = ft_split(input, ' ');
	return (0);
}
