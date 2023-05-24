#include "main.h"

/**
 * builtin_cd - change directory
 * Return: void
 * @d: data struct input
 */
void builtin_cd(data *dta)
{
	char *dir = dta->av[1];
	char cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("getcwd() error");
	_setenv(dta, "PWD", cwd);
	if (!dir)
		dir = _getenv("HOME");
	if (chdir(dir) == -1)
		perror("cd");
	else
	{
		_setenv(dta, "OLDPWD", _getenv("PWD"));
		if (getcwd(cwd, sizeof(cwd)) == NULL)
			perror("getcwd() error");
		_setenv(dta, "PWD", cwd);
	}
}

