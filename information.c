#include "main.h"

/**
 * c_info - initializes inf_t struct
 * @n: struct address
 */
void c_info(inf_t *n)
{
	n->arg = NULL;
	n->argv = NULL;
	n->path = NULL;
	n->argc = 0;
}

/**
 * s_info - initializes inf_t struct
 * @n: struct address
 * @a: argument vector
 */
void s_info(info_t *n, char **a)
{
	int i = 0;

	n->fname = a[0];
	if (n->arg)
	{
		n->argv = stow(n->arg, " \t");
		if (!n->argv)
		{

			n->argv = malloc(sizeof(char *) * 2);
			if (n->argv)
			{
				n->argv[0] = _sdup(n->arg);
				n->argv[1] = NULL;
			}
		}
		for (i = 0; n->argv && n->argv[i]; i++)
			;
		n->argc = i;

		replace_alias(n);
		replace_vars(n);
	}
}

/**
 * f_info - frees info_t struct fields
 * @n: struct address
 * @a: true
 */
void f_info(inf_t *n, int a)
{
	_free_(n->argv);
	n->argv = NULL;
	n->path = NULL;
	if (a)
	{
		if (!n->cmd_buf)
			free(n->arg);
		if (n->env)
			f_list(&(n->env));
		if (n->history)
			f_list(&(n->history));
		if (n->alias)
			f_list(&(n->alias));
		_free_(n->environ);
			n->environ = NULL;
		 _bfr_((void **)n->cmd_buf);
		if (n->readfd > 2)
			close(n->readfd);
		_putchar(BUF_FLUSH);
	}
}
