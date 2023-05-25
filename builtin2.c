#include "main.h"
/**
 * builtN_cd - change directory
 * @d: data
 */
void builtN_cd(data *d)
{
	char *dir = d->av[1];
	char cawwd[256];

	if (getcawwd(cawwd, sizeof(cawwd)) == NULL)
		perror("getcawwd() error");
	_setenv(d, "PWD", cawwd);
	if (!dir)
		dir = _getenv("HOME");
	if (chdir(dir) == -1)
		perror("cd");
	else
	{
		_setenv(d, "OLDPWD", _getenv("PWD"));
		if (getcawwd(cawwd, sizeof(cawwd)) == NULL)
			perror("getcawwd() error");
		_setenv(d, "PWD", cawwd);
	}
}

