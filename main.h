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

/* _str_.c */
int _slen(char *);
int _scmp(char *, char *);
char *start(const char *, const char *);
char *_str_cat(char *, char *);

/* _str_2.c */
char *_scpy(char *, char *);
char *_sdup(const char *);
void _put(char *);
int _putchar(char);

/* _str_3.c  */
char *_sncpy(char *, char *, int);
char *_sncat(char *, char *, int);
char *_schr(char *, char);


#endif
