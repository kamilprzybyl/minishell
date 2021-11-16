#include "../inc/minishell.h"

int	pwd()
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
	return (0);
}

int	cd(char *path)
{
	// DIR *dir;

	// dir = opendir(path);
	// if (dir == NULL) {
	// 	printf ("bash: cd: %s: No such file or directory", path);
	// 	return (1);
	// }
	chdir(path);
	// closedir(dir);
	return (0);
}

int main()
{
	cd("../");
	pwd();
}