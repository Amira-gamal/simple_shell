#include "main.h"

/**
 *_eput - prints an input
 * @s: the string to be printed
 * Return: Nothing
 */
void _eput(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		_echar(s[i]);
		i++;
	}
}

/**
 * _echar - writes the character
 * @x: print character
 * Return: On success 1
 */
int _echar(char x)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (x == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (x != BUF_FLUSH)
		buf[i++] = x;
	return (1);
}

/**
 * _putf - writes the character
 * @x: print character
 * @f: The filedescriptor
 * Return: On success 1.
 */
int _putf(char x, int f)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (x == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(f, buf, i);
		i = 0;
	}
	if (x != BUF_FLUSH)
		buf[i++] = x;
	return (1);
}

/**
 *_putsf - prints an input string
 * @s: the string
 * @f: the filedescriptor
 * Return: the number of chars put
 */
int _putsf(char *s, int f)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s)
	{
		i += _putfd(*s++, f);
	}
	return (i);
}

