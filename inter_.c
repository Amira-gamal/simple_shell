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
 *@str: the string
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *str)
{
	int i, x = 1, y = 0, z;
	unsigned int r = 0;

	for (i = 0;  str[i] != '\0' && y != 2; i++)
	{
		if (str[i] == '-')
			x *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			y = 1;
			r *= 10;
			r += (str[i] - '0');
		}
		else if (y == 1)
			y = 2;
	}

	if (x == -1)
		z = -r;
	else
		z = r;

	return (z);
}

