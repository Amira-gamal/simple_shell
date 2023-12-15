#include "main.h"

/**
 * _inter_ - returns true if shell is interactive
 * @x: struct address
 * Return: 1 if interactive mode
 */
int _inter_(inf_t *x)
{
	return (isatty(STDIN_FILENO) && x->readfd <= 2);
}

/**
 * is_del - find if character is a delimeter
 * @x: the char
 * @d: the delimeter
 * Return: 1 if true
 */
int is_del(char x, char *d)
{
	while (*d)
		if (*d++ == x)
			return (1);
	return (0);
}

/**
 *_isalpha - find alphabetic character
 *@x: The character
 *Return: 1 if x is alphabetic
 */

int _isalpha(int x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@s: the string
 *Return: 0 if no numbers in string, converted number otherwise
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
