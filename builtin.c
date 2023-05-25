#include "main.h"

/**
 * exec_builtN - check if built in and then exec
 * Return: 1 if built in, 0 if not
 * @d: data struct input
 */
int exec_builtN(data *d)
{
	builtN builtN[] = {
		{"exit", builtN_exit},
		{"env", builtN_env},
		{"setenv", builtN_setenv},
		{"unsetenv", builtN_unsetenv},
		{"cd", builtN_cd},
		{NULL, NULL},
	};
	int i = 0;
	for (i = 0; builtN[i].cmd; i++)
	{
		if (_strcmp(d->av[0], builtN[i].cmd) == 0)
		{
			builtN[i].f(d);
			return (1);
		}
	}
	return (0);
}

/**
 * builtN_unsetenv - Remove an environment variable
 * @d: data struct input
 * Return: void
 */
void builtN_unsetenv(data *d)
{
	int i, j;
	int len;

	(void)d;
	if (!d->av[1] || !getenv(d->av[1]))
	{
		_perror(d->nomShell, "variable not found.");
		return;
	}
	len = strlen(d->av[1]);
	for (i = 0; environ[i]; i++)
		if (strncmp(environ[i], d->av[1], len) == 0 && environ[i][len] == '=')
			for (j = i; environ[j]; j++)
				environ[j] = environ[j + 1];
}

/**
 * builtN_env - prints the current environment
 * Return: void
 * @d: data struct input
 */

void builtN_env(data *d)
{
	int i = 0;

	(void)d;
	while (environ[i])
	{
		_printf(environ[i]);
		_printf("\n");
		i++;
	}
}

/**
 * builtN_exit - exits the shell
 * @d: data struct input
 * Return: void
 */
void builtN_exit(data *d)
{
	if (d->av[1] && _isnumber(d->av[1]))
		d->last_exit_stats = atoi(d->av[1]);
	free_array(d->av);
	free(d->cmd);
	if (d->flag_setenv)
		free_array(environ);
	exit(d->last_exit_stats);
}

/**
 * builtN_setenv - Initialize a new environment variable,
 * or modify an existing one
 * @d: data struct input
 * Return: void
 */
void builtN_setenv(data *d)
{
	(void)d;
	if (d->av[1] && d->av[2])
	{
		if (_setenv(d, d->av[1], d->av[2]) == -1)
		{
			perror("setenv");
		}
	}
}





