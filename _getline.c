#include "main.h"

/**
 * _getline_helper - getline helper function
 * @n: int input
 * @Lptr: string input
 * Return: int
 */

int _getline_helper(char **Lptr, size_t *n)
{	if (*Lptr == NULL || *n == 0)
	{*n = 128;
		*Lptr = malloc(*n);
		if (*Lptr == NULL)
			return (-1);
	}
	return (0);
}

/**
 * _getline - reads the input from FILE
 * @Lptr: string input
 * @stmr: FILE input 
 * @n: int input
 * 
 * Return: ssize_t
 */

ssize_t _getline(char **Lptr, size_t *n, FILE *stmr)
{
	ssize_t bRead = 0;
	size_t pos = 0, newS;
	static char buf[READ_BUF_SIZE];static size_t buffS, bufffPos;char *nwBufff;
	if (Lptr == NULL || n == NULL || stmr == NULL
		|| _getline_helper(Lptr, n) == -1)
		return (-1);
	while (1)
	{
		if (bufffPos >= buffS)
		{
			bRead = read(stmr->_fileno, buf, READ_BUF_SIZE);
			if (bRead <= 0 && pos == 0)
				return (-1);
			else if (bRead <= 0)
				break;
			buffS = bRead;
			bufffPos = 0;
		}
		if (pos >= *n - 1)
		{
			newS = *n * 2;
			nwBufff = realloc(*Lptr, newS);
			if (nwBufff == NULL)
				return (-1);
			*Lptr = nwBufff;
			*n = newS;
		}
		(*Lptr)[pos++] = buf[bufffPos++];
		if ((*Lptr)[pos - 1] == '\n')
			break;
	}
	(*Lptr)[pos] = '\0';
	return (pos);
}


