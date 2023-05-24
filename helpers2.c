#include "main.h"

/**
 * _perror - print in stderr
 * @str2: message error
 * @str1: nm of shell program
 * Return: void
 */
void _perror(const char *str1, const char *str2)
{
	if (!str1 || !str2)
		return;

	while (*str1)
	{
		write(STDERR_FILENO, str1, 1);
		str1++;
	}

	write(STDERR_FILENO, ": ", 2);

	while (*str2)
	{
		write(STDERR_FILENO, str2, 1);
		str2++;
	}
	write(STDERR_FILENO, "\n", 1);
}


/**
 * _trim - remove leading and trailing spaces and tabs from a string
 * @str: string input
 * Return: void.
 */

void _trim(char *str)
{
	int i, j, len = _strlen(str);

	for (i = 0; i < len && (str[i] == ' ' || str[i] == '\t'); i++)
		;

	for (j = 0; i < len ; i++, j++)
		str[j] = str[i];

	str[j] = '\0';

	for (i = _strlen(str) - 1; i > 0 && (str[i] == ' ' || str[i] == '\t'); i--)
		str[i] = '\0';
}


/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: pointer void
 * @new_s: unsigned int
 *
 * Return: the newly allocated memory
 */
void *_realloc(void *ptr, unsigned int new_s)
{	char *p;
	unsigned int i, tp = new_s, old-s = sizeof(ptr);
	if (old-s == new_s)
		return (ptr);
	if (ptr == NULL)
		return (malloc(new_s));

	if (new_s > old-s)
		tp = old-s;

	if (new_s == 0)
	{
		free(ptr);
		return (NULL);
	}

	p = malloc(new_s);

	for (i = 0; i < tp; i++)
		p[i] = ((char *)ptr)[i];
	free(ptr);
	return (p);
}

