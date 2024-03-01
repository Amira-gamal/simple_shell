#include "main.h"

/**
 * my_exit - exits the shell
 * @f: Structure containing potential arguments
 *  Return: exits with a given exit status
 */
int my_exit(info_t *f)
{
	int exitcheck;

	if (f->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = _err_atoi(f->argv[1]);
		if (exitcheck == -1)
		{
			f->status = 2;
			_print_ero(f, "Illegal number: ");
			_eputs(f->argv[1]);
			_eputchar('\n');
			return (1);
		}
		f->err_num = _err_atoi(f->argv[1]);
		return (-2);
	}
	f->err_num = -1;
	return (-2);
}

/**
 * my_cd - changes the current directory
 * @f: Structure containing potential arguments.
 *  Return: Always 0
 */
int my_cd(info_t *f)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!f->argv[1])
	{
		dir = _getenv(f, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = _getenv(f, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(f->argv[1], "-") == 0)
	{
		if (!_getenv(f, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(f, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = _getenv(f, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(f->argv[1]);
	if (chdir_ret == -1)
	{
		_print_ero(f, "can't cd to ");
		_eputs(f->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(f, "OLDPWD", _getenv(f, "PWD="));
		_setenv(f, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * my_help - changes the current directory of the process
 * @f: Structure containing potential arguments.
 *  Return: Always 0
 */
int my_help(info_t *f)
{
	char **arg_array;

	arg_array = f->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}

