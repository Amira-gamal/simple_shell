#include "main.h"

/**
 * _scat - concatenates two strings
 * @i: the destination buffer
 * @x: the source buffer
 *
 * Return: pointer to iination buffer
 */
char *_scat(char *i, char *x)
{
	char *z = i;

	while (*i)
		i++;
	while (*x)
		*i++ = *x++;
	*i = *x;
	return (z);
}

/**
 * start- checks if y starts with x
 * @x: string
 * @y: the substring
 * Return: address
 */
char *start(const char *x, const char *y)
{
	for (; *y; y++, x++)
	{
		if (*y != *x)
			return (NULL);
	}
	return ((char *)x);
}

/**
 * _slen - the length of a string
 * @n: the string
 * Return: integer length
 */
int _slen(char *n)
{
	int i = 0;

	if (!n)
		return (0);

	for (i = 0; *n != '\0'; i++)
		*n++;
	return (i);
}

/**
 * _scom- performs lexicogarphic comparison of two strangs.
 * @n1: string
 * @n2: string
 * Return: returns
 */
int _scom(char *n1, char *n2)
{
	for (; *n1 && *n2; n1++, n2++)
	{
		if (*n1 != *n2)
			return (*n1 - *n2);
	}
	if (*n1 == *n2)
		return (0);
	else
		return (*n1 < *n2 ? -1 : 1);
}
