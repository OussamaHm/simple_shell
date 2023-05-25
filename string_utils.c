#include "main.h"

/**
 * _strlen - return the nbr of char in str
 * @sotoringuu: string input
 * Return: nbr of char in str.
 */

unsigned int _strlen(char *sotoringuu)
{
	unsigned int i;

	for (i = 0; sotoringuu[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strcmp - compares two strings.
 *
 * @sotoring1: input const string
 * @sotoring2: input const string
 *
 * Return: returns an integer indicating the result of the comparison,
 *	as follows:
 *		• 0, if the sotoring1 and sotoring2 are equal
 *		• a negative value if sotoring1 is less than sotoring2
 *		• a positive value if sotoring1 is greater than sotoring2
 */
int _strcmp(const char *sotoring1, const char *sotoring2)
{
	int i;
	int res = 0;

	for (i = 0; sotoring1[i] != '\0' && sotoring2[i] != '\0'; i++)
	{
		if (sotoring1[i] != sotoring2[i])
		{
			res = sotoring1[i] - sotoring2[i];
			break;
		}
	}

	return (res);
}

/**
 * _strncmp - compares two strings.
 *
 * @sotoring1: input const string
 * @sotoring2: input const string
 * @n: input int
 *
 * Return: returns an integer indicating the result of the comparison,
 *	as follows:
 *		• 0, if the sotoring1 and sotoring2 are equal
 *		• a negative value if sotoring1 is less than sotoring2
 *		• a positive value if sotoring1 is greater than sotoring2
 */
int _strncmp(const char *sotoring1, const char *sotoring2, int n)
{
	int i;
	int res = 0;

	for (i = 0; sotoring1[i] != '\0' && sotoring2[i] != '\0'; i++)
	{

		if (i >= n)
			break;
		if (sotoring1[i] != sotoring2[i])
		{
			res = sotoring1[i] - sotoring2[i];
			break;
		}
	}

	return (res);
}

/**
 * _strcpy - copy src to dest .
 *
 * @dest: input char *
 * @src: input const char *
 *
 * Return: char *
 */
char *_strcpy(char *dest, const char *src)
{
	int len;

	for (len = 0; src[len] != '\0'; ++len)
	{
		dest[len] = src[len];
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * _strcat - appends the src string to the dest string,
 *
 * @dest: input string
 * @src: input const string
 *
 * Return: void
 */
char *_strcat(char *dest, const char *src)
{
	char *result = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (result);
}


