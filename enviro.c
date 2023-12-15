#include "main.h"

/**
 * _myenviro - print current environment
 * @f: Structure containing potential arguments
 * Return: Always 0
 */
int _myenviro(inf_t *f)
{
	p_list_s(f->env);
	return (0);
}

/**
 * _getenviro - gets the value of environ
 * @f: Structure containing potential arguments
 * @n: env var name
 * Return: the value
 */
char *_getenviro(inf_t *f, const char *n)
{
	list_t *node = f->env;
	char *p;

	while (node)
	{
		p = start(node->str, n);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _setenviro - Initialize a new environment variable
 * @f: Structure containing potential arguments
 *  Return: Always 0
 */
int _setenviro(inf_t *f)
{
	if (f->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenviron(f, f->argv[1], f->argv[2]))
		return (0);
	return (1);
}

/**
 * _unsetenviro - Remove an environment variable
 * @f: Structure containing potential arguments
 *  Return: Always 0
 */
int _unsetenviro(inf_t *f)
{
	int i;

	if (f->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= f->argc; i++)
		_unsetenviron(f, f->argv[i]);

	return (0);
}


/**
 * populate_enviro_lis - populates env linked list
 * @f: Structure containing potential arguments.
 * Return: Always 0
 */
int populate_enviro_lis(inf_t *f)
{
	list_t *nod = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		_add_nod_end(&nod, environ[i], 0);
	f->env = nod;
	return (0);
}
