#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
/**
 * struct list - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct list
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function
 *@arg: a string generated from getline
 *@argv: an array of strings
 *@path: a string path
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy
 *@environ: custom modified copy
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ
 *@status: the return status of the last command
 *@cmd_buf: address of pointer to cmd_buf
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read
 *@histcount: the history line
 */
typedef struct passinformation
{
    list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
    int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
    char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
    char *arg;
	char **argv;
	char *path;
} inf_t;

/* _str_.c */
int _slen(char *);
int _scom(char *, char *);
char *start(const char *, const char *);
char *_scat(char *, char *);


/* _str_2.c */
char *_scpy(char *, char *);
char *_sdup(const char *);
void _put(char *);
int _putchar(char);

/* _str_3.c  */
char *_sncpy(char *, char *, int);
char *_sncat(char *, char *, int);
char *_schr(char *, char);

/* _str_4.c */
char **stow(char *, char *);
char **stow2(char *, char);

/* mem.c */
char *mem(char *, char, unsigned int);
void _free_(char **);
void *_realloc_(void *, unsigned int, unsigned int);

/* mem2.c */
int _bfr_(void **);


/* inter_.c */
int _inter_(inf_t *);
int is_del(char, char *);
int _isalpha(int);
int _atoi(char *);

/* erratoi_.c */
int _eatoi(char *);
void p_error(inf_t *, char *);
int p_deci(int, int);
char *conve_num(long int, int, int);
void rm_com(char *);

/*linked_lists.c*/
list_t *_add_nod(list_t **, const char *, int);
list_t *_add_nod_end(list_t **, const char *, int);
size_t p_list_s(const list_t *);
int del_nod_index(list_t **, unsigned int);
void f_list(list_t **);

/* linked_lists2.c module */
size_t list_len(const list_t *);
char **list_strings(list_t *);
size_t print_list(const list_t *);
list_t *starts_with(list_t *, char *, char);
ssize_t node_index(list_t *, list_t *);

/*error.c*/
void _eput(char *);
int _echar(char);
int _putf(char c, int fd);
int _putsf(char *str, int fd);

/* information.c module */
void c_info(inf_t *);
void s_info(inf_t *, char **);
void f_info(inf_t *, int);

/* enviro.c module */
char *_getenviro(inf_t *, const char *);
int _myenvrio(inf_t *);
int _setenvrio(inf_t *);
int _unsetenvrio(inf_t *);
int populate_enviro_lis(inf_t *);

/* enviro2.c module */
char **get_environ(inf_t *);
int _unsetenviron(inf_t *, char *);
int _setenviron(inf_t *, char *, char *);
