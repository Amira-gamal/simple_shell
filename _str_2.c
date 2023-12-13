#include "main.h"

/**
 * _sdup - duplicates the string
 * @s: the string
 * Return: pointer to the duplicated
 */
char *_sdup(const char *s)
{
	int len = 0;
	char *r;

	if (s == NULL)
		return (NULL);
	while (*s++)
		len++;
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	for (len++; len--;)
		r[len] = *--s;
	return (r);
}

/**
 * _putchar - writes the character
 * @chr: print character
 * Return: 1 On success
 * On error, return -1
 */
int _putchar(char chr)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (chr == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}
	if (chr != BUF_FLUSH)
		buf[i++] = chr;
	return (1);
}

/**
 * _scpy - copies the string
 * @x: string
 * @z: string
 *
 * Return: pointer to ination
 */
char *_scpy(char *x, char *z)
{
	int i = 0;

	if (x == z || z == 0)
		return (x);
	for (i = 0; z[i]; i++)
	{
		x[i] = z[i];
	}
	x[i] = 0;
	return (x);
}

/**
 *_put - prints an input
 *@s: the string
 * Return: Nothing
 */
void _put(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}
