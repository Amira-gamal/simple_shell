#include "main.h"

/**
 * my_history - displays the history list, one command by line.
 * @f: Structure containing potential arguments.
 *  Return: Always 0
 */
int my_history(info_t *f)
{
	print_list(f->history);
	return (0);
}

/**
 * _unset_alias - sets alias to string
 * @f: parameter struct
 * @s: the string alias
 * Return: Always 0 on success, 1 on error
 */
int _unset_alias(info_t *f, char *s)
{
	char *p, c;
	int ret;

	p = _strchr(s, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(f->alias),
		get_node_index(f->alias, node_starts_with(f->alias, s, -1)));
	*p = c;
	return (ret);
}

/**
 * _set_alias - sets alias to string
 * @f: parameter struct
 * @s: the string alias
 * Return: Always 0 on success, 1 on error
 */
int _set_alias(info_t *f, char *s)
{
	char *p;

	p = _strchr(s, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (_unset_alias(f, s));

	_unset_alias(f, s);
	return (add_node_end(&(f->alias), s, 0) == NULL);
}

/**
 * _print_alias - prints an alias string
 * @node: the alias node
 * Return: Always 0 on success, 1 on error
 */
int _print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _my_alias - mimics the alias builtin (man alias)
 * @f: Structure containing potential arguments.
 *  Return: Always 0
 */
int _my_alias(info_t *f)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (f->argc == 1)
	{
		node = f->alias;
		while (node)
		{
			_print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; f->argv[i]; i++)
	{
		p = _strchr(f->argv[i], '=');
		if (p)
			_set_alias(f, f->argv[i]);
		else
			_print_alias(node_starts_with(f->alias, f->argv[i], '='));
	}

	return (0);
}

