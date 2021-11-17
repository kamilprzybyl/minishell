#include "../../inc/minishell.h"

void	ft_cd(t_data *data, char **tokens)
{
	// DIR *dir;
	(void)data;
	// dir = opendir(path);
	// if (dir == NULL) {
	// 	printf ("bash: cd: %s: No such file or directory", path);
	// 	return (1);
	// }
	chdir(tokens[0]);
	// closedir(dir);
}
