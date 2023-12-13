#include "main.h"

/**
 * _bfr_ - frees a pointer and NULLs
 * @p: address of the pointer to free
 * Return: 1 if freed, otherwise 0.
 */
int _bfr_(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
