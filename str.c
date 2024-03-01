#include "main.h"

/**
* _strcat - a function that concatenates two strings.
* @dest: an input string
* @src: an input string
* Return: A pointer to the resulting string
*/

char *_strcat(char *dest, char *src)
{
	int i, x;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (x = 0; src[x] != '\0'; x++)
	{
		dest[i++] = src[x];
	}
	return (dest);
}
/**
* _strlen - returns the length of a string
* @s: string to evaluate
* Return: the length of the string
*/

int _strlen(char *s)
{
	int i;

	for (i = 0; *s != '\0'; s++)
	{
		i++;
	}
	return (i);
}

/**
* _strcmp - compares two strings
* @s1: first string to compare
* @s2: second string to compare
* Return: The difference s1 - s2
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystac: string to search
 * @needl: the substring to find
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystac, const char *needl)
{
	while (*needl)
		if (*needl++ != *haystac++)
			return (NULL);
	return ((char *)haystac);
}

