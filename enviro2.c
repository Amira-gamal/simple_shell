#include "main.h"

/**
 * get_environ - returns the string array
 * @f: Structure containing potential arguments
 * Return: Always 0
 */
char **get_environ(inf_t *f)
{
	if (!f->environ || f->env_changed)
	{
		f->environ = list_str(f->env);
		f->env_changed = 0;
	}

	return (f->environ);
}

/**
 * _unsetenviron - Remove an environment variable
 * @f: Structure containing potential arguments.
 * @v: the string env var property
 * Return: 1 on delete, 0 otherwise
 */
int _unsetenviron(inf_t *f, char *v)
{
	list_t *nod = f->env;
	size_t i = 0;
	char *ptr;

	if (!nod || !v)
		return (0);

	while (nod)
	{
		ptr = starts_with(nod->str, v);
		if (ptr && *ptr == '=')
		{
			f->env_changed = del_nod_index(&(f->env), i);
			i = 0;
			nod = f->env;
			continue;
		}
		nod = nod->next;
		i++;
	}
	return (f->env_changed);
}

/**
 * _setenviro - Initialize a new environment variable
 * @f: Structure containing potential arguments.
 * @v: the string env var property
 * @val: the string env var value
 *  Return: Always 0
 */
int _setenviron(inf_t *f, char *v, char *val)
{
	char *buf = NULL;
	list_t *nod;
	char *p;

	if (!v || !val)
		return (0);

	buf = malloc(_slen(v) + _slen(val) + 2);
	if (!buf)
		return (1);
	_scpy(buf, v);
	_scat(buf, "=");
	_scat(buf, val);
	nod = f->env;
	while (nod)
	{
		p = start(nod->str, v);
		if (p && *p == '=')
		{
			free(nod->str);
			nod->str = buf;
			f->env_changed = 1;
			return (0);
		}
		nod = nod->next;
	}
	_add_nod_end(&(f->env), buf, 0);
	free(buf);
	f->env_changed = 1;
	return (0);
}
