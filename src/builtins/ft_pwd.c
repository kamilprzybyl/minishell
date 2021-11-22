#include "../../inc/minishell.h"

void	ft_pwd(t_data *data)
{
	char cwd[100];

	(void)data;
	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("%s\n", cwd);
	}
	else
		perror("error");
}
