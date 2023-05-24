#include "main.h"

/**
 * _getenv - retrieves the value of an environment variable.
 * @nm: string input
 * Return: value of an environment variable
 */

char *_getenv(char *nm)
{
	int i = -1;
	size_t nm_len;

	if (nm == NULL || *nm == '\0')
		return (NULL);
	if (environ == NULL)
		return (NULL);

	nm_len = _strlen(nm);

	while (environ[++i])
	{
		if (!_strncmp(environ[i], nm, nm_len) && environ[i][nm_len] == '=')
		{
			return (environ[i] + nm_len + 1);
		}
	}
	return (NULL);
}

/**
 * _which - locate the executable file associated with a given command.
 * @d: string input
 * Return: void
 */
int _which(data *d)
{
	char *tk, *path,
		*paths = malloc(_strlen(_getenv("PATH") ? _getenv("PATH") : "") + 1);
	size_t tk_len;
	int find = -1;

	if (!_getenv("PATH"))
		goto step_out;
	_strcpy(paths, _getenv("PATH"));
	if (paths == NULL)
		goto step_out;
	tk = strtok(paths, ":");
	while (tk)
	{
		tk_len = _strlen(tk) + _strlen(d->av[0]) + 2;
		path = malloc(tk_len);
		if (path == NULL)
			return (find);
		_strcpy(path, tk);
		_strcat(path, "/");
		_strcat(path, d->av[0]);
		if (access(path, F_OK) == 0)
		{
			free(d->av[0]);
			d->av[0] = _strdup(path);
			free(path);
			find = 0;
			break;
		}
		free(path);
		tk = strtok(NULL, ":");
	}
step_out:
	free(paths);
	return (find);
}

/**
 * create_new_tr - Initialize a new environment variable,
 *  or modify an existing one
 * @nm: variable nm
 * @value: variable value
 * Return: void
 */
char *create_new_tr(char *nm, char *value)
{
	size_t new_l = strlen(nm) + strlen(value) + 2;
	char *new_tr = malloc(new_l);

	if (new_tr == NULL)
		return (NULL);

	strcpy(new_tr, nm);
	strcat(new_tr, "=");
	strcat(new_tr, value);

	return (new_tr);
}
/**
 * _new_vir - Initialize a new environment variable,
 *  or modify an existing one
 * @nm: variable nm
 * @value: variable value
 * Return: void
 */
char **_new_vir(char *nm, char *value)
{
	int env_len = 0, i = 0;
	char *new_tr;
	char **new_vir;

	while (environ[env_len])
		env_len++;
	new_tr = create_new_tr(nm, value);
	if (new_tr == NULL)
		return (NULL);
	new_vir = _getenv(nm) ? malloc((env_len + 1) * sizeof(char *))
								: malloc((env_len + 2) * sizeof(char *));

	if (!new_vir)
	{
		free(new_tr);
		return (NULL);
	}
	for (i = 0; environ[i]; i++)
	{
		new_vir[i] = malloc(strlen(environ[i]) + 1);
		if (!new_vir[i])
		{
			free_arr(new_vir);
			free(new_tr);
			return (NULL);
		}
		if (strncmp(environ[i], nm, strlen(nm)) == 0
		&& environ[i][strlen(nm)] == '=')
			strcpy(new_vir[i], new_tr);
		else
			strcpy(new_vir[i], environ[i]);
	}
	if (!_getenv(nm))
	{
		new_vir[env_len] = new_tr;
		new_vir[env_len + 1] = NULL;
	}
	else
		new_vir[env_len] = NULL;
	return (new_vir);
}

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @d: to use the flag
 * @nm: variable nm
 * @value: variable value
 * Return: void
 */
int _setenv(data *d, char *nm, char *value)
{
	char **new_vir;
	if (!nm || !value)
		return (-1);
	new_vir = _new_vir(nm, value);
	if (!new_vir)
		return (-1);
	environ = new_vir;
	d->flag_setenv = 1;
	return (0);
}


