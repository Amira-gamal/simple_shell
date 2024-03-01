#include "main.h"

/**
 * _interactiv_ - returns true if shell is interactive
 * @f:struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
int _interactiv_(info_t *f)
{
	return (isatty(STDIN_FILENO) && f->readfd <= 2);
}

/**
 * is_delim - checks if character is delimeter
 * @x: the char to check
 * @deli: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char x, char *deli)
{
	while (*deli)
		if (*deli++ == x)
			return (1);
	return (0);
}

/**
*_isalpha - controls if a character is alphabetical
*@c: character to be verified
*Return: return 0 or 1
*/
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
* _atoi - Converts a string to an integer.
* @s: The string to be converted.
* Return: The integer value of the converted string.
*/

int _atoi(char *s)
{
	int x = 1;
	unsigned int i = 0;

	do {
		if (*s == '-')
			x *= -1;
		else if (*s >= '0' && *s <= '9')
			i = (i * 10) + (*s - '0');
		else if (i > 0)
			break;
	}
	while (*s++)
		;
	return (i * x);
}


