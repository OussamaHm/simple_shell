#include "main.h"

/**
 * _perror - print in stderr
 * @stringuu2: message error
 * @stringuu1: name of shell program
 * Return: void
 */
void _perror(const char *stringuu1, const char *stringuu2)
{
	if (!stringuu1 || !stringuu2)
		return;
	while (*stringuu1)
	{
		write(STDERR_FILENO, stringuu1, 1);
		stringuu1++;
	}
	write(STDERR_FILENO, ": ", 2);
	while (*stringuu2)
	{
		write(STDERR_FILENO, stringuu2, 1);
		stringuu2++;
	}
	write(STDERR_FILENO, "\n", 1);
}


/**
 * _trim - remove leading and trailing spaces and tabs from a string
 * Return: void.
 * @str: string input
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
 * @nouveau_siz: unsigned int 
 * @ptr: pointer void
 *
 * Return: the newly allocated memory
 */
void *_realloc(void *ptr, unsigned int nouveau_siz)
{
	char *p;
	unsigned int i, tp = nouveau_siz, ancien_si = sizeof(ptr);

	if (ancien_si == nouveau_siz)
		return (ptr);
	if (ptr == NULL)
		return (malloc(nouveau_siz));

	if (nouveau_siz > ancien_si)
		tp = ancien_si;

	if (nouveau_siz == 0)
	{
		free(ptr);
		return (NULL);
	}

	p = malloc(nouveau_siz);

	for (i = 0; i < tp; i++)
		p[i] = ((char *)ptr)[i];
	free(ptr);
	return (p);
}


