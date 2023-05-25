#include "main.h"

/**
 * _printf - print a string to stander out put
 * @sotringuu: string input
 * Return: void
 */
void _printf(const char *sotringuu)
{
	if (!sotringuu)
		return;
	while (*sotringuu)
	{
		write(STDOUT_FILENO, sotringuu, 1);
		sotringuu++;
	}
}

/**
 * free_array - free an array of pointers
 * @ar: array of pointers
 * Return: void
 */
void free_array(char **ar)
{
	int i;

	if (!ar)
		return;

	for (i = 0; ar[i]; i++)
	{
		free(ar[i]);
		ar[i] = NULL;
	}

	free(ar);
}

/**
 * split - split a given string by a delimouta
 * @delimouta: string input
 * @d: data struct input
 * Return: void
 */
void split(data *d, const char *delimouta)
{
	char *token;
	int ntoken = 0;

	d->av = malloc(2 * sizeof(char *));
	if (d->av == NULL)
	{
		free(d->cmd);
		perror(d->nomShell);
		exit(EXIT_FAILURE);
	}
	d->av[0] = NULL;
	d->av[1] = NULL;

	token = strtok(d->cmd, delimouta);
	while (token)
	{
		d->av = _realloc(d->av, (ntoken + 2) * sizeof(char *));
		if (d->av == NULL)
			goto free;
		d->av[ntoken] = _strdup(token);
		if (d->av[ntoken] == NULL)
			goto free;
		ntoken++;
		token = strtok(NULL, delimouta);
	}
	d->av[ntoken] = NULL;
	return;
free:
	free_array(d->av);
	free(d->cmd);
	perror(d->nomShell);
	exit(EXIT_FAILURE);
}

/**
 * init_data - init data
 * @d: data struct input
 * @nomShell: string input
 * Return: void
 */

void init_data(data *d, const char *nomShell)
{
	d->cmd = NULL;
	d->av = NULL;
	d->nomShell = nomShell;
	d->last_exit_stats = EXIT_SUCCESS;
	d->flag_setenv = 0;
}

/**
 * read_cmd - get the commend from the prompt and structure it into data struct
 * @d: data struct input
 * Return: void
 */
void read_cmd(data *d)
{
	size_t n = 0;
	ssize_t mynread;
	int i = 0;

	mynread = _getline(&d->cmd, &n, stdin);

	if (mynread == -1)
	{
		free(d->cmd);
		exit(EXIT_SUCCESS);
	}

	d->cmd[mynread - 1] = '\0';
	_trim(d->cmd);
	/* replace hashtag with end of line we can also do it with strtok*/
	for (i = 0; d->cmd[i] != '\0'; i++)
	{
		if (d->cmd[i] == '#')
		{
			d->cmd[i] = '\0';
			break;
		}
	}
	_trim(d->cmd);
}


