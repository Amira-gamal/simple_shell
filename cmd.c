
/**
 * _is_cmd - determines if a file is an executable command
 * @f: the info struct
 * @p: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int _is_cmd(info_t *f, char *p)
{
	struct stat st;

	(void)f;
	if (!p || stat(p, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * _dup_chars - duplicates characters
 * @pstr: the PATH string
 * @str: starting index
 * @st: stopping index
 *
 * Return: pointer to new buffer
 */
char *_dup_chars(char *pstr, int str, int st)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = str; i < st; i++)
		if (pstr[i] != ':')
			buf[k++] = pstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * _find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *_find_path(info_t *f, char *pstr, char *c)
{
	int i = 0, curr_pos = 0;
	char *p;

	if (!pstr)
		return (NULL);
	if ((_strlen(c) > 2) && starts_with(c, "./"))
	{
		if (_is_cmd(f, c))
			return (c);
	}
	while (1)
	{
		if (!pstr[i] || pstr[i] == ':')
		{
			path = _dup_chars(pstr, curr_pos, i);
			if (!*path)
				_strcat(p, cmd);
			else
			{
				_strcat(p, "/");
				_strcat(p, cmd);
			}
			if _is_cmd(f, p))
				return (p);
			if (!pstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

