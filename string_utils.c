#include "main.h"

/**
 * _strlen - return the nbr of char in str
 * @str: string input
 * Return: nbr of char in str.
 */
unsigned int _strlen(char *str)
{unsigned int i;
	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
/**
 * _strcmp - compares two strings.
 *
 * @s1: input const string
 * @s2: input const string
 *
 * Return: returns an integer indicating the rs of the comparison,
 *	as follows:
 *		• 0, if the s1 and s2 are equal
 *		• a positive value if s1 is greater than s2
 *		• a negative value if s1 is less than s2
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * _strncmp - compares two strings.
 *
 * Return: returns an integer indicating the rs of the comparison,
 *	as follows:
 *		• 0, if the s1 and s2 are equal
 *		• a negative value if s1 is less than s2
 *		• a positive value if s1 is greater than s2
 * 
 * @s1: input const string
 * @s2: input const string
 * @n: input int
 *
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{

		if (i >= n)
			break;
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * _strcpy - copy src to desty .
 *
 * @desty: input char *
 * @src: input const char *
 *
 * Return: char *
 */
char *_strcpy(char *desty, const char *src)
{
	int len;

	for (len = 0; src[len] != '\0'; ++len)
	{
		desty[len] = src[len];
	}
	desty[len] = '\0';
	return (desty);
}

/**
 * _strcat - appends the src string to the desty string,
 *
 * @desty: input string
 * @src: input const string
 *
 * Return: void
 */
char *_strcat(char *desty, const char *src)
{
	char *rs = desty;

	while (*desty != '\0')
		desty++;

	while (*src != '\0')
	{
		*desty = *src;
		desty++;
		src++;
	}
	*desty = '\0';

	return (rs);
}

