#include "../../inc/minishell.h"

int	pwd(t_data *data, char **tokens)
{
	char cwd[100];

	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("%s\n", cwd);
	}
	else
	{
		perror("error");
		return (1);
	}
}
