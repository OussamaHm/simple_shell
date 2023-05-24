#include "main.h"
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 *
 * @str: string input
 *
 * Return: pointer
 */
char *_strdup(const char *str)
{
	int i, len = 0;
	char *rs;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	rs = (char *)malloc((len + 1) * sizeof(char));

	if (rs == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		rs[i] = str[i];

	return (rs);
}


/**
 * _isnumber - check if a string is a number
 * @stt: string to be checked
 * Return: void
 */
int _isnumber(const char *stt)
{
	if (stt == NULL || stt[0] == '\0')
		return (0);
	while (*stt)
	{
		if (!_isdigit(*stt))
			return (0);
		stt++;
	}
	return (1);
}


/**
 * _isdigit - check if charachter is number
 * @c: charachter
 * Return: 1 if its a digit 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}


