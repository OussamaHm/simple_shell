#include "main.h"

/**
 * _printf - print a string to stander out put
 * @str: string input
 * Return: void
 */

void _printf(const char *str)
{
	if (!str)
		return;
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}

/**
 * free_arr - free an arr of pointers
 * @arr: arr of pointers
 * Return: void
 */
void free_arr(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
}

/**
 * split - split a given string by a delimiter
 * @d: data struct input
 * @delim: string input
 * Return: void
 */
void split(data *d, const char *delim)
{
	char *tk;
	int ntk = 0;

	d->av = malloc(2 * sizeof(char *));
	if (d->av == NULL)
	{
		free(d->cmd);
		perror(d->shell_nm);
		exit(EXIT_FAILURE);
	}
	d->av[0] = NULL;
	d->av[1] = NULL;

	tk = strtok(d->cmd, delim);
	while (tk)
	{
		d->av = _realloc(d->av, (ntk + 2) * sizeof(char *));
		if (d->av == NULL)
			goto free;
		d->av[ntk] = _strdup(tk);
		if (d->av[ntk] == NULL)
			goto free;
		ntk++;
		tk = strtok(NULL, delim);
	}
	d->av[ntk] = NULL;
	return;
free:
	free_arr(d->av);
	free(d->cmd);
	perror(d->shell_nm);
	exit(EXIT_FAILURE);
}

/**
 * init_data - init data
 * @d: data struct input
 * @shell_nm: string input
 * Return: void
 */

void init_data(data *d, const char *shell_nm)
{
	d->cmd = NULL;
	d->av = NULL;
	d->shell_nm = shell_nm;
	d->last_exit_stt = EXIT_SUCCESS;
	d->flag_setenv = 0;
}

/**
 * read_cmd - get the commend from the prpt and structure it into data struct
 * @d: data struct input
 * Return: void
 */
void read_cmd(data *d)
{
	size_t n = 0;
	ssize_t nread;
	int i = 0;

	nread = _getline(&d->cmd, &n, stdin);

	if (nread == -1)
	{
		free(d->cmd);
		exit(EXIT_SUCCESS);
	}

	d->cmd[nread - 1] = '\0';
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

