#ifndef MAIN_H
#define MAIN_H


#define PROMPT "#csisfun$ "

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/**
 * struct data - holds the main data.
 * @av: Array of tks to pass for execve
 * @cmd: The user input, the command line
 * @shell_nm: The nm of the shell program
 * @last_exit_stt: last exit stt of last command executed
 * @flag_setenv: 1 if user did exec setenv (use it to free memory)
 */
typedef struct data
{
	char **av;
	char *cmd;
	const char *shell_nm;
	int last_exit_stt;
	int flag_setenv;
} data;

/**
 * struct builtin - holds the main data.
 * @cmd: built in cmd
 * @f: function of builtin cmd
 */
typedef struct builtin
{
	const char *cmd;
	void (*f)(data *d);
} builtin;

/* builtin.c */
int exec_builtin(data *d);
void builtin_exit(data *d);
void builtin_env(data *d);
void builtin_setenv(data *d);
void builtin_unsetenv(data *d);
void builtin_cd(data *d);


/* helpers.c */
void _printf(const char *str);
void free_arr(char **arr);
void split(data *d, const char *delim);
void init_data(data *d, const char *shell_nm);
void read_cmd(data *d);

/* helpers2.c */
void _perror(const char *str1, const char *str2);
void _trim(char *str);
void *_realloc(void *ptr, unsigned int new_s);

/* exec.c */
void start_process(data *d);
void handler_sigint(int sig);
void _exec(data *d);

/* path.c */
char *_getenv(char *nm);
int _which(data *d);
int _setenv(data *d, char *nm, char *value);

/* string_utils.c */
unsigned int _strlen(char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_strcpy(char *desty, const char *src);
char *_strcat(char *desty, const char *src);


/* string_utils2.c */
char *_strdup(const char *str);
int _isnumber(const char *stt);
int _isdigit(int c);

/* _getline.c */
#define READ_BUF_SIZE 1024

ssize_t _getline(char **Lptr, size_t *n, FILE *stm);


#endif

