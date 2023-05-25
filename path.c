#include "main.h"
/**
 * _getenv - retrieves the value of an environment variable.
 * @name: string input
 * Return: value of an environment variable
 */

char *_getenv(char *name)
{
	int i = -1;
	size_t nomlen;
	if (name == NULL || *name == '\0')
		return (NULL);
	if (environ == NULL)
		return (NULL);
	nomlen = _strlen(name);
	while (environ[++i])
	{
		if (!_strncmp(environ[i], name, nomlen) && environ[i][nomlen] == '=')
		{
			return (environ[i] + nomlen + 1);
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
	char *token, *path,
		*paths = malloc(_strlen(_getenv("PATH") ? _getenv("PATH") : "") + 1);
	size_t token_len;
	int find = -1;
	if (!_getenv("PATH"))
		goto step_out;
	_strcpy(paths, _getenv("PATH"));
	if (paths == NULL)
		goto step_out;
	token = strtok(paths, ":");
	while (token)
	{
		token_len = _strlen(token) + _strlen(d->av[0]) + 2;
		path = malloc(token_len);
		if (path == NULL)
			return (find);
		_strcpy(path, token);
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
		token = strtok(NULL, ":");
	}
step_out:
	free(paths);
	return (find);
}
/**
 * _envir - Initialize a new environment variable,
 *  or modify an existing one
 * @name: variable name
 * @value: variable value
 * Return: void
 */
char **_envir(char *name, char *value)
{
	int env_len = 0, i = 0;
	char *entree;
	char **envir;

	while (environ[env_len])
		env_len++;
	entree = create_entree(name, value);
	if (entree == NULL)
		return (NULL);
	envir = _getenv(name) ? malloc((env_len + 1) * sizeof(char *))
								: malloc((env_len + 2) * sizeof(char *));

	if (!envir)
	{
		free(entree);
		return (NULL);
	}
	for (i = 0; environ[i]; i++)
	{
		envir[i] = malloc(strlen(environ[i]) + 1);
		if (!envir[i])
		{
			free_array(envir);
			free(entree);
			return (NULL);
		}
		if (strncmp(environ[i], name, strlen(name)) == 0
		&& environ[i][strlen(name)] == '=')
			strcpy(envir[i], entree);
		else
			strcpy(envir[i], environ[i]);
	}
	if (!_getenv(name))
	{
		envir[env_len] = entree;
		envir[env_len + 1] = NULL;
	}
	else
		envir[env_len] = NULL;
	return (envir);
}

/**
 * create_entree - Initialize a new environment variable,
 *  or modify an existing one
 * @name: variable name
 * @value: variable value
 * Return: void
 */
char *create_entree(char *name, char *value)
{
	size_t new_len = strlen(name) + strlen(value) + 2;
	char *entree = malloc(new_len);
	if (entree == NULL)
		return (NULL);
	strcpy(entree, name);
	strcat(entree, "=");
	strcat(entree, value);

	return (entree);
}

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @d: to use the flag
 * @value: variable value
 * @name: variable name
 * Return: void
 */
int _setenv(data *d, char *name, char *value)
{
	char **envir;

	if (!name || !value)
		return (-1);

	envir = _envir(name, value);
	if (!envir)
		return (-1);
	environ = envir;
	d->flag_setenv = 1;

	return (0);
}


