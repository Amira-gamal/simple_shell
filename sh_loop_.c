#include "main.h"

/**
 * _hsh_ - main shell loop
 * @f: the parameter & return info struct
 * @v: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int _hsh_(info_t *f, char **v)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_info(f);
		if (_interactiv_(f))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(f);
		if (r != -1)
		{
			set_info(f, v);
			builtin_ret = f_builtin(f);
			if (builtin_ret == -1)
				f_cmd(f);
		}
		else if (_interactiv_(f))
			_putchar('\n');
		free_info(f, 0);
	}
	write_history(f);
	free_info(f, 1);
	if (!_interactiv_(f) && f->status)
		exit(f->status);
	if (builtin_ret == -2)
	{
		if (f->err_num == -1)
			exit(f->status);
		exit(f->err_num);
	}
	return (builtin_ret);
}

/**
 * f_builtin - finds a builtin command
 * @f: the parameter & return info struct
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int f_builtin(info_t *f)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", my_exit},
		{"env", _myenv},
		{"help", my_help},
		{"history", my_history},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", my_cd},
		{"alias", _my_alias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(f->argv[0], builtintbl[i].type) == 0)
		{
			f->line_count++;
			built_in_ret = builtintbl[i].func(f);
			break;
		}
	return (built_in_ret);
}

/**
 * f_cmd - finds a command in PATH
 * @f: the parameter & return info struct
 * Return: void
 */
void f_cmd(info_t *f)
{
	char *path = NULL;
	int i, k;

	f->path = f->argv[0];
	if (f->linecount_flag == 1)
	{
		f->line_count++;
		f->linecount_flag = 0;
	}
	for (i = 0, k = 0; f->arg[i]; i++)
		if (!is_delim(f->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = _find_path(f, _getenv(f, "PATH="), f->argv[0]);
	if (path)
	{
		f->path = path;
		fork_cmd(f);
	}
	else
	{
		if ((_interactiv_(f) || _getenv(f, "PATH=")
			|| f->argv[0][0] == '/') && _is_cmd(f, f->argv[0]))
			fork_cmd(f);
		else if (*(f->arg) != '\n')
		{
			f->status = 127;
			_print_ero(f, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks a an exec thread to run cmd
 * @f: the parameter & return info struct
 * Return: void
 */
void fork_cmd(info_t *f)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(f->path, f->argv, get_environ(f)) == -1)
		{
			free_info(f, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(f->status));
		if (WIFEXITED(f->status))
		{
			f->status = WEXITSTATUS(f->status);
			if (f->status == 126)
				_print_ero(f, "Permission denied\n");
		}
	}
}

